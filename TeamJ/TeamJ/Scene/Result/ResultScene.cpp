#include "ResultScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "../../Object/UI/Score/Score.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

// コンストラクタ
ResultScene::ResultScene():menu_num(0),push_flg(false),cnt(0),score_display(0),sound{},font_scene_name(0),font_result(0),font_button(0),font_rank(0),rank(0),rank_cnt(0),score(0)
{
}

// デストラクタ
ResultScene::~ResultScene()
{
}

// 初期化処理
void ResultScene::Initialize()
{
	// 変数の初期化
	menu_num = 0;
	cnt = 0;
	push_flg = false;
	score_display = 0;
	rank = 0;
	rank_cnt = 0;
	bgm_flg = false;

	// スコア取得
	score = Score::score;

	// 画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/ranking.png");
	background_image = tmp[0];
	tmp = rm->GetImages("Resource/Images/buttonLong_brown.png");
	button_img.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/buttonLong_beige.png");
	button_img.push_back(tmp[0]);

	// 音源の読み込み
	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/cursol_move.mp3");
	sound[0] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/cursol_push.mp3");
	sound[1] = tmp2;

	//BGMの読み込み
	int tmp3;
	tmp3 = rm->GetSounds("Resource/Sounds/Fothracha.mp3");
	result_bgm = tmp3;

	// フォントデータ作成
	font_scene_name = CreateFontToHandle("Stencil", 50, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_result = CreateFontToHandle("Stencil", 75, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_button = CreateFontToHandle("Stencil", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_rank = CreateFontToHandle("Stencil", 90, -1, DX_FONTTYPE_ANTIALIASING_4X4);
}

// 更新処理
eSceneType ResultScene::Update()
{
	InputManager* input = InputManager::GetInstance();

	AddDisplayScore();
	ChangeRankBlendParam();

	//一度だけこの処理を通るようにする
	if (bgm_flg == false)
	{
		//BGMの再生を最初から流れるよう設定
		SetSoundCurrentTime(0, result_bgm);
		//BGMのの再生
		PlaySoundMem(result_bgm, DX_PLAYTYPE_LOOP, FALSE);

		//trueにし、何度も更新しないようにする
		bgm_flg = true;
	}

	// 左スティックでボタン移動
	if (push_flg == false)
	{
		if (input->GetLeftStick().x == 1.0f || input->GetKeyInputState(KEY_INPUT_D) == eInputState::ePress)
		{
			push_flg = true;
			PlaySoundMem(sound[0], DX_PLAYTYPE_BACK, TRUE);

			if (menu_num == 0)
			{
				menu_num++;
			}
			else
			{
				menu_num--;
			}
		}
		if (input->GetLeftStick().x == -1.0f || input->GetKeyInputState(KEY_INPUT_A) == eInputState::ePress)
		{
			push_flg = true;
			PlaySoundMem(sound[0], DX_PLAYTYPE_BACK, TRUE);

			if (menu_num == 0)
			{
				menu_num = 1;
			}
			else
			{
				menu_num--;
			}
		}
	}

	// 連続入力制御
	if (push_flg == true)
	{
		cnt++;
		if (cnt >= 15)
		{
			push_flg = false;
			cnt = 0;
		}
	}

	// Bボタンで決定：選択したボタンの画面に遷移する
	if (input->GetButtonDown(XINPUT_BUTTON_B) || input->GetKeyInputState(KEY_INPUT_B) == eInputState::ePress)
	{
		PlaySoundMem(sound[1], DX_PLAYTYPE_BACK, TRUE);

		if (menu_num == 0)
		{
			return eSceneType::eInGame;
		}
		else
		{
			return eSceneType::eTitle;
		}
	}

	return GetNowSceneType();
}

// 描画処理
void ResultScene::Draw() const
{
	// 背景画像描画
	DrawExtendGraph(-25, -50, 665,530, background_image, TRUE);

	// ボタンの描画
	if (menu_num == 0)
	{
		// リスタートボタン描画
		DrawGraph(50, 370, button_img[1], TRUE);
		DrawStringToHandle(125, 380, "RETRY", 0x000000, font_button);

		// タイトルボタン描画
		DrawGraph(365, 375, button_img[0], TRUE);
		DrawStringToHandle(425, 380, "TITlE", 0xffffff, font_button);
	}
	else
	{
		//リスタートボタン描画
		DrawGraph(50, 375, button_img[0], TRUE);
		DrawStringToHandle(100, 380, "RETRY", 0xffffff, font_button);

		// タイトルボタン描画
		DrawGraph(330, 370, button_img[1], TRUE);
		DrawStringToHandle(415, 380, "TITlE", 0x000000, font_button);
	}

	// リザルト文字描画
	DrawStringToHandle(240, 40, "RESULT", 0x000000, font_scene_name);

	// スコア描画
	DrawFormatStringToHandle(65, 120, 0x000000, font_result,"SCORE:%06d",score_display);
	DrawLineAA(65.0f, 200.0f, 580.0f, 200.0f, 0x000000);
	DrawLineAA(65.0f, 201.0f, 580.0f, 201.0f, 0x000000);
	DrawLineAA(65.0f, 202.0f, 580.0f, 202.0f, 0x000000);

	// ランク描画：スコアに応じてランクの表示を変える
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, rank_cnt);
	if (score >= 5000)
	{
		DrawCircleAA(255.0f - 30.0f, 265.0f, 48.0f, 32, 0xfd7e00, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 49.0f, 32, 0xfd7e00, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 50.0f, 32, 0xfd7e00, FALSE);
		DrawRotaStringToHandle(274 - 30, 264, 1.0f, 1.0f, 45.0f, 45.0f, -PI / 180 * 10.0f, 0xfd7e00, font_rank, 0x000000, FALSE, "S");
	}
	else if (score >= 3000)
	{
		DrawCircleAA(255.0f - 30.0f, 265.0f, 48.0f, 32, 0xff0000, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 49.0f, 32, 0xff0000, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 50.0f, 32, 0xff0000, FALSE);
		DrawRotaStringToHandle(270 - 30, 262, 1.0f, 1.0f, 45.0f, 45.0f, -PI / 180 * 10.0f, 0xff0000, font_rank, 0x000000, FALSE, "A");
	}
	else if (score >= 1000)
	{
		DrawCircleAA(255.0f - 30.0f, 265.0f, 48.0f, 32, 0x2214b6, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 49.0f, 32, 0x2214b6, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 50.0f, 32, 0x2214b6, FALSE);
		DrawRotaStringToHandle(271 - 30, 264, 1.0f, 1.0f, 45.0f, 45.0f, -PI / 180 * 10.0f, 0x2214b6, font_rank, 0x000000, FALSE, "B");
	}
	else
	{
		DrawCircleAA(255.0f - 30.0f, 265.0f, 48.0f, 32, 0x005931, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 49.0f, 32, 0x005931, FALSE);
		DrawCircleAA(255.0f - 30.0f, 265.0f, 50.0f, 32, 0x005931, FALSE);
		DrawRotaStringToHandle(271 - 30, 266, 1.0f, 1.0f, 45.0f, 45.0f, -PI / 180 * 10.0f, 0x005931, font_rank, 0x000000, FALSE, "C");
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	// ランク文字描画
	DrawStringToHandle(330 -30, 240, "RANK", 0x000000, font_result);
	DrawLineAA(160.0f, 323.0f, 510.0f, 323.0f, 0x000000);
	DrawLineAA(160.0f, 324.0f, 510.0f, 324.0f, 0x000000);
	DrawLineAA(160.0f, 325.0f, 510.0f, 325.0f, 0x000000);
}

// 終了時処理
void ResultScene::Finalize()
{
	//BGMの再生を止める
	StopSoundMem(result_bgm);

	//フラグのリセット
	bgm_flg = false;
}

// 現在のシーン情報を返す
eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}

// ランク透明度変更
void ResultScene::ChangeRankBlendParam()
{
	if (rank_cnt < 254)
	{
		rank_cnt += 2;
	}
	else
	{
		rank_cnt = 255;
	}
}

// 表示するスコアの値を増やす
void ResultScene::AddDisplayScore()
{
	if (score_display < score)
	{
		if (score >= 5000)
		{

		}
		else if(score >= 3000)
		{
			 
		}
		else if (score >= 1000)
		{

		}
		else if (score >= 500)
		{

		}
		else
		{
			
		}

		score_display += 10;
	}
	else
	{
		score_display = score;
	}
}
