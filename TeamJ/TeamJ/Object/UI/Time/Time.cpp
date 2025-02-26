#include "Time.h"
#include "../../../Utility/ResourceManager.h"
#include "DxLib.h"

Time::Time() : cnt(0),time(0),bar_width(0.0f),bar_height(0.0f),font_time(0),sound(0)
{
}

Time::~Time()
{
}

void Time::Initialize()
{
	// 変数初期化
	cnt = 3600;
	//cnt = 1200; // デバック用
	time = 60;
	bar_width = 300.0f;
	bar_height = 20.0f;

	// 画像読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/bar.png");
	img.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/bar_inside.png");
	img.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/bar_inside1.png");
	img.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/bar_inside2.png");
	img.push_back(tmp[0]);

	// 音源読み込み
	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/Countdown02-2.mp3");
	sound = tmp2; 

	ChangeVolumeSoundMem(255, sound);

	// フォント作成
	font_time = CreateFontToHandle("Stencil", 23, -1, DX_FONTTYPE_ANTIALIASING_4X4);
}

void Time::Update()
{
	
	if (cnt <= 0)
	{
		cnt = 0;
	}
	else
	{
		cnt--;
	}

	if (cnt == 180)
	{
		PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
	}
}

void Time::Draw() const
{
	// 時間描画
	DrawStringToHandle(10, 21, "TIME", 0xfdddcb, font_time);

	// バーの中描画
	if (cnt <= 30)
	{// 残り0.5秒だったら

		DrawBoxAA(70.0f, 20.0f, 70.0f, 22.0f + bar_height, 0xd95e4d, TRUE);
	}
	else if (cnt <= 600)
	{// 10秒より小さかったら

		DrawBoxAA(70.0f, 20.0f, 70.0f + (bar_width / 3600.0f * (float)cnt), 22.0f + bar_height, 0xd95e4d, TRUE);
	}
	//else if(cnt <= 1200)
	//{// 20秒より小さかったら

	//	DrawBoxAA(70.0f, 20.0f, 70.0f + (bar_width / 3600.0f * (float)cnt), 22.0f + bar_height, 0xe37e58, TRUE);
	//}
	else
	{// 上記以外

		DrawBoxAA(70.0f, 20.0f, 70.0f + (bar_width / 3600.0f * (float)cnt), 22.0f + bar_height, 0xfdddcb, TRUE);
	}

	// バーの枠描画（線を太くするために2個描画）
	DrawBoxAA(70.0f, 20.0f, 70.0f + bar_width, 24.0f + bar_height, 0xebcebe, FALSE);
	DrawBoxAA(71.0f, 21.0f, 69.0f + bar_width, 23.0f + bar_height, 0xebcebe, FALSE);
}

void Time::FInalize()
{
}
