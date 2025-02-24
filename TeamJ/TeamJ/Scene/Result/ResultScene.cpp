#include "ResultScene.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "../../Object/UI/Score/Score.h"
#include "DxLib.h"

// コンストラクタ
ResultScene::ResultScene():menu_num(0),background_img(0),push_flg(false),cnt(0),sound{},font_scene_name(0),font_result(0),font_button(0)
{
}

// デストラクタ
ResultScene::~ResultScene()
{
}

// 初期化処理
void ResultScene::Initialize()
{
	menu_num = 0;
	push_flg = false;
	cnt = 0;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/22639450.png");
	background_img = tmp[0];

	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/cursol_move.mp3");
	sound[0] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/cursol_push.mp3");
	sound[1] = tmp2;

	font_scene_name = CreateFontToHandle("Fortuner Heavy",60,-1, DX_FONTTYPE_ANTIALIASING);
	font_result = CreateFontToHandle("Fortuner Heavy", 75, -1, DX_FONTTYPE_ANTIALIASING);
}

// 更新処理
eSceneType ResultScene::Update()
{
	InputManager* input = InputManager::GetInstance();

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

	if (push_flg == true)
	{
		cnt++;
		if (cnt >= 15)
		{
			push_flg = false;
			cnt = 0;
		}
	}

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
	DrawGraph(0, 0, background_img, FALSE);

	SetFontSize(16);
	// ボタンの描画
	if (menu_num == 0)
	{
		// リスタートボタンを暗くする
		// 描画輝度のセット
		SetDrawBright(128, 128, 128);
		// リスタートボタン描画
		DrawBox(140, 360, 140 + BUTTON_WIDTH, 360 + BUTTON_HEIGHT, 0xffffff, TRUE);
		DrawString(160, 380, "RESTART", 0x000000);
		// 描画輝度を元に戻す
		SetDrawBright(255, 255, 255);

		// タイトルボタン描画
		DrawBox(400, 360, 400 + BUTTON_WIDTH, 360 + BUTTON_HEIGHT, 0xffffff, TRUE);
		DrawString(430, 380, "TITLE", 0x000000);
	}
	else
	{
		//リスタートボタン描画
		DrawBox(140, 360, 140 + BUTTON_WIDTH, 360 + BUTTON_HEIGHT, 0xffffff, TRUE);
		DrawString(160, 380, "RESTART", 0x000000);

		// タイトルボタンを暗くする
		// 描画輝度のセット
		SetDrawBright(128, 128, 128);
		// タイトルボタン描画
		DrawBox(400, 360, 400 + BUTTON_WIDTH, 360 + BUTTON_HEIGHT, 0xffffff, TRUE);
		DrawString(430, 380, "TITLE", 0x000000);
		// 描画輝度を元に戻す
		SetDrawBright(255, 255, 255);
	}


	SetFontSize(35);
	//DrawString(270, 20, "RESULT", 0xffffff);
	DrawStringToHandle(200, 25, "RESULT", 0xffffff, font_scene_name);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(100, 90, 540, 320, 0xffffff, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetFontSize(50);
	//DrawFormatString(150, 140, 0x000000, "SCORE:%07d", Score::score);
	DrawStringToHandle(70, 140, "SCORE:00000", 0xffffff, font_result);
	SetFontSize(50);
	//DrawString(250, 230, "RANK:S", 0x000000);
	DrawStringToHandle(250, 230, "RANK:S", 0xffffff, font_result);
	SetFontSize(20);
}

// 終了時処理
void ResultScene::Finalize()
{

}

// 現在のシーン情報を返す
eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}
