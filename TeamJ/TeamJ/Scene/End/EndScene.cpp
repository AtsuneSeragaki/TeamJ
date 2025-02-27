#include "EndScene.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"

// コンストラクタ
EndScene::EndScene():cnt(0)
{
}

// デストラクタ
EndScene::~EndScene()
{
}

// 初期化処理
void EndScene::Initialize()
{
	location = Vector2D(320.0f, 400.0f);

	cnt = 60;
	bgm = 0;
	image = 0;
	sound = 0;

	push_flg = false;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/buttonLong_beige.png");
	image = tmp[0];
	tmp = rm->GetImages("Resource/Images/end.png");
	background_image = tmp[0];

	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/B00023_kamatamago_kouya-miti.mp3");
	bgm = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/gun_shot.mp3");
	sound = tmp2;

	//font_button = CreateFontToHandle("Stencil", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4);

	ChangeVolumeSoundMem(127, bgm);
}

// 更新処理
eSceneType EndScene::Update()
{
	//InputManager* input = InputManager::GetInstance();

	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, FALSE);

	/*if (push_flg == false)
	{
		if (input->GetButtonDown(XINPUT_BUTTON_B))
		{
			push_flg = true;
			PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
		}
	}
	else
	{
		if (cnt > 0)
		{
			cnt--;
		}
		else
		{
			cnt = 0;
			return eSceneType::eNone;
		}
	}*/

	cnt++;

	if (cnt >= 260)
	{
		return eSceneType::eNone;
	}

	return GetNowSceneType();
}

// 描画処理
void EndScene::Draw() const
{
	/*DrawRotaGraphF(location.x, location.y, 1.0f, 0.0f, image, TRUE, FALSE);
	DrawStringToHandle(location.x - 37, location.y - 25, "END", 0x000000, font_button);*/

	DrawGraph(0, 0, background_image, FALSE);
}

// 終了時処理
void EndScene::Finalize()
{
	DeleteGraph(background_image);
}

// 現在のシーン情報を返す
eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType::eEnd;
}
