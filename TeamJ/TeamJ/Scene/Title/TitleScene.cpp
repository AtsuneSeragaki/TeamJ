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
	location2 = Vector2D(320.0f, 200.0f);
	location3 = Vector2D(320.0f, 300.0f);
	location4 = Vector2D(320.0f, 400.0f);
	box2_size = Vector2D(160.0f, 60.0f);
	box3_size = Vector2D(160.0f, 60.0f);
	box4_size = Vector2D(160.0f, 60.0f);

	menu_num = 0;

	push_flg = false;
	cnt = 0;
}

// 更新処理
eSceneType TitleScene::Update()
{
	InputManager* input = InputManager::GetInstance();
	if (push_flg == false)
	{
		if (input->GetLeftStick().y == -1.0f)
		{
			push_flg = true;
			if (menu_num < 2)
			{
				menu_num++;
			}
			else
			{
				menu_num = 0;
			}

		}
		else if (input->GetLeftStick().y == 1.0f)
		{
			push_flg = true;
			if (menu_num > 0)
			{
				menu_num--;
			}
			else
			{
				menu_num = 2;
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
	SetFontSize(20);
	DrawString(10, 10, "TITLE", 0xffffff);

	if (menu_num == 0)
	{
		SetDrawBright(128, 128, 128);
		DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);
	}
	else if (menu_num == 1)
	{
		DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(128, 128, 128);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);
	}
	else
	{
		DrawBoxAA(location2.x - box2_size.x * 0.5f, location2.y - box2_size.y * 0.5f, location2.x + box2_size.x * 0.5f, location2.y + box2_size.y * 0.5f, 0xffffff, TRUE);
		DrawBoxAA(location3.x - box3_size.x * 0.5f, location3.y - box3_size.y * 0.5f, location3.x + box3_size.x * 0.5f, location3.y + box3_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(128, 128, 128);
		DrawBoxAA(location4.x - box4_size.x * 0.5f, location4.y - box4_size.y * 0.5f, location4.x + box4_size.x * 0.5f, location4.y + box4_size.y * 0.5f, 0xffffff, TRUE);
		SetDrawBright(255, 255, 255);
	}
}

// 終了時処理
void TitleScene::Finalize()
{
}

// 現在のシーン情報を返す
eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}
