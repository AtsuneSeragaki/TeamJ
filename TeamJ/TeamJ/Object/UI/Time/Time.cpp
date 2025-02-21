#include "Time.h"
#include "DxLib.h"

Time::Time() : cnt(0),time(0),bar_width(0),bar_height(0)
{
}

Time::~Time()
{
}

void Time::Initialize()
{
	cnt = 0;
	time = 60;
	bar_width = 300;
	bar_height = 20;
}

void Time::Update()
{
	cnt++;

	// 1秒たったら時間を減らす
	if (cnt >= 60)
	{
		time--;
		cnt = 0;
	}

	// デバック用(0秒になったら60秒にリセット)
	if (time <= 0)
	{
		time = 60;
	}
}

void Time::Draw() const
{
	// 時間描画
	DrawFormatString(10, 32, 0xffffff, "%d", time);

	// バーの中描画
	if (time <= 10)
	{// 10秒より小さかったら
		DrawBox(40, 30, 30 + (bar_width / 60 * time), 30 + bar_height, 0xff0000, TRUE);
	}
	else if(time <= 20)
	{// 20秒より小さかったら
		DrawBox(40, 30, 30 + (bar_width / 60 * time), 30 + bar_height, 0xff7f50, TRUE);
	}
	else
	{// 上記以外
		DrawBox(40, 30, 30 + (bar_width / 60 * time), 30 + bar_height, 0x009999, TRUE);
	}

	// バーの枠描画（線を太くするために2個描画）
	DrawBox(40, 28, 30 + bar_width, 32 + bar_height, 0xffffff, FALSE);
	DrawBox(41, 29, 29 + bar_width, 31 + bar_height, 0xffffff, FALSE);
}

void Time::FInalize()
{
}
