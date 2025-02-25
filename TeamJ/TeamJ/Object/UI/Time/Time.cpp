#include "Time.h"
#include "../../../Utility/ResourceManager.h"
#include "DxLib.h"

Time::Time() : cnt(0),time(0),bar_width(0.0f),bar_height(0.0f)
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
}

void Time::Update()
{
	cnt--;

	// デバック用
	//cnt -= 10;

	// カウントが0になったらリセット
	/*if (cnt <= 0)
	{
		cnt = 3600;
	}*/
}

void Time::Draw() const
{
	// 時間描画
	//DrawFormatString(10, 32, 0xffffff, "%d", time);
	SetFontSize(20);
	DrawString(10, 23,"TIME",0xffffff);

	// バーの中描画
	if (cnt <= 30)
	{
		DrawExtendGraph(BAR_X + 3.0f, BAR_Y, BAR_X + 3.0f + (bar_width / 3600.0f * (float)cnt), BAR_Y + BAR_HEIGHT + 3, img[3], TRUE);
	}
	else if (cnt <= 600)
	{// 10秒より小さかったら
		//DrawBoxAA(40.0f, 30.0f, 40.0f + (bar_width / 3600.0f * (float)cnt), 30.0f + bar_height, 0xff0000, TRUE);
		//DrawExtendGraph(43.0f, 30.0f, 43.0f + (bar_width / 3600.0f * (float)cnt), 30.0f + bar_height + 5,img[3],TRUE);
		DrawBoxAA(BAR_X + 5.0f, BAR_Y + 2.0f, BAR_X + (BAR_WIDTH / 3600.0f * (float)cnt), BAR_Y + BAR_HEIGHT, 0xf7464d, TRUE);
	}
	else if(cnt <= 1200)
	{// 20秒より小さかったら
		//DrawBoxAA(40.0f, 30.0f, 40.0f + (bar_width / 3600.0f * (float)cnt), 30.0f + bar_height, 0xff7f50, TRUE);
		//DrawExtendGraph(43.0f, 30.0f, 43.0f + (bar_width / 3600.0f * (float)cnt), 30.0f + bar_height + 5, img[2], TRUE);
		DrawBoxAA(BAR_X + 5.0f, BAR_Y + 2.0f, BAR_X + (BAR_WIDTH / 3600.0f * (float)cnt), BAR_Y + BAR_HEIGHT, 0xea843e, TRUE);
	}
	else if(cnt <= 3570)
	{// 上記以外
		
		DrawBoxAA(BAR_X + 5.0f, BAR_Y + 2.0f, BAR_X + (BAR_WIDTH / 3600.0f * (float)cnt), BAR_Y + BAR_HEIGHT, 0x00a8f3, TRUE);
		
	}
	else
	{
		DrawExtendGraph(BAR_X + 3.0f, BAR_Y, BAR_X + 3.0f + (BAR_WIDTH / 3600.0f * (float)cnt), BAR_Y + BAR_HEIGHT + 3, img[1], TRUE);
	}

	// バーの枠描画（線を太くするために2個描画）
	//DrawBoxAA(40.0f, 28.0f, 40.0f + bar_width, 32.0f + bar_height, 0xffffff, FALSE);
	//DrawBoxAA(41.0f, 29.0f, 39.0f + bar_width, 31.0f + bar_height, 0xffffff, FALSE);
	DrawGraph(BAR_X, BAR_Y, img[0], TRUE);
}

void Time::FInalize()
{
}
