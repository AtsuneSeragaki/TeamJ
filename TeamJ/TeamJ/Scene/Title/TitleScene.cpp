#include "TitleScene.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"

// コンストラクタ
TitleScene::TitleScene()
{
}

// デストラクタ
TitleScene::~TitleScene()
{
}

// 初期化処理
void TitleScene::Initialize()
{
	location2 = Vector2D(320.0f, 260.0f);
	location3 = Vector2D(320.0f, 340.0f);
	location4 = Vector2D(320.0f, 420.0f);
	box2_size = Vector2D(160.0f, 60.0f);
	box3_size = Vector2D(160.0f, 60.0f);
	box4_size = Vector2D(160.0f, 60.0f);

	menu_num = 0;

	push_flg = false;
	cnt = 0;

	play_bgm = false;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp= rm->GetImages("Resource/Images/Title.png");
	background_image = tmp[0];
	tmp = rm->GetImages("Resource/Images/buttonLong_brown.png");
	image[0] = tmp[0];
	tmp = rm->GetImages("Resource/Images/buttonLong_beige.png");
	image[1] = tmp[0];

	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/gun_shot.mp3");
	sound2[0] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/cursor_sound.mp3");
	sound2[1] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/title_bgm.mp3");
	bgm = tmp2;

	font_scene_name = CreateFontToHandle("Stencil", 80, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_button = CreateFontToHandle("Stencil", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4);
}

// 更新処理
eSceneType TitleScene::Update()
{
	// BGM再生
	if (play_bgm == false)
	{
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, TRUE);
		play_bgm = true;
	}

	InputManager* input = InputManager::GetInstance();
	if (push_flg == false)
	{
		if (input->GetLeftStick().y == -1.0f)
		{
			push_flg = true;
			if (menu_num < 2)
			{
				menu_num++;
				PlaySoundMem(sound2[1], DX_PLAYTYPE_BACK, TRUE);
			}
			else
			{
				menu_num = 0;
				PlaySoundMem(sound2[1], DX_PLAYTYPE_BACK, TRUE);
			}

		}
		else if (input->GetLeftStick().y == 1.0f)
		{
			push_flg = true;
			if (menu_num > 0)
			{
				menu_num--;
				PlaySoundMem(sound2[1], DX_PLAYTYPE_BACK, TRUE);
			}
			else
			{
				menu_num = 2;
				PlaySoundMem(sound2[1], DX_PLAYTYPE_BACK, TRUE);
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
	if (input->GetButtonDown(XINPUT_BUTTON_B))
	{
		PlaySoundMem(sound2[0], DX_PLAYTYPE_BACK, TRUE);
		if (menu_num == 0)
		{
			return eSceneType::eInGame;
		}
		else if (menu_num == 1)
		{
			return eSceneType::eRanking;
		}
		else
		{
			return eSceneType::eEnd;
		}
	}
	return GetNowSceneType();


}

// 描画処理
void TitleScene::Draw() const
{
	DrawGraph(-223, 0, background_image, FALSE);

	DrawStringToHandle(75, 75, "Bottle Shot", 0x000000, font_scene_name);
	DrawStringToHandle(70, 70, "Bottle Shot", 0xffffff, font_scene_name);
	
	SetFontSize(20);
	//DrawString(10, 10, "Bottle Shot", 0xffffff);

	if (menu_num == 0)
	{
		/*SetDrawBright(128, 128, 128);
		DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);*/
		DrawRotaGraphF(location2.x, location2.y, 1.0f, 0.0f, image[1], TRUE, FALSE);
		DrawStringToHandle(location2.x - 60, location2.y - 25, "START", 0x000000, font_button);
		DrawRotaGraphF(location3.x, location3.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location3.x - 87, location3.y - 25, "RANKING", 0xffffff, font_button);
		DrawRotaGraphF(location4.x, location4.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location4.x - 37, location4.y - 25, "END", 0xffffff, font_button);
	}
	else if (menu_num == 1)
	{
		/*DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(128, 128, 128);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);*/
		DrawRotaGraphF(location2.x, location2.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location2.x - 60, location2.y - 25, "START", 0xffffff, font_button);
		DrawRotaGraphF(location3.x, location3.y, 1.0f, 0.0f, image[1], TRUE, FALSE);
		DrawStringToHandle(location3.x - 87, location3.y - 25, "RANKING", 0x000000, font_button);
		DrawRotaGraphF(location4.x, location4.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location4.x - 37, location4.y - 25, "END", 0xffffff, font_button);
	}
	else
	{
		/*DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(128, 128, 128);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);*/
		DrawRotaGraphF(location2.x, location2.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location2.x - 60, location2.y - 25, "START", 0xffffff, font_button);
		DrawRotaGraphF(location3.x, location3.y, 1.0f, 0.0f, image[0], TRUE, FALSE);
		DrawStringToHandle(location3.x - 87, location3.y - 25, "RANKING", 0xffffff, font_button);
		DrawRotaGraphF(location4.x, location4.y, 1.0f, 0.0f, image[1], TRUE, FALSE);
		DrawStringToHandle(location4.x - 37, location4.y - 25, "END", 0x000000, font_button);
	}

	

}

// 終了時処理
void TitleScene::Finalize()
{
	StopSoundMem(bgm);
	play_bgm = false;

	DeleteFontToHandle(font_button);
	DeleteFontToHandle(font_scene_name);
}

// 現在のシーン情報を返す
eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}
