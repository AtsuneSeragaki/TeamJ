#include "Score.h"
#include "DxLib.h"

int Score::score = 5000;

Score::Score() : /*score(0),*/add_score(0),subtract_score(0),add_flg(false),subtract_flg(false)
{
}

Score::~Score()
{
}

void Score::Initialize()
{
	add_score = 0;
	subtract_score = 0;
	add_flg = false;
	subtract_flg = false;
}

void Score::Update()
{
	if (add_score > 0)
	{
		add_flg = true;
	}

	if (subtract_score < 0)
	{
		subtract_flg = true;
	}

	if (add_flg == true && subtract_flg == true)
	{
		add_score += subtract_score;
		subtract_score = 0;

		if (add_score < 0)
		{
			score -= 5;
			add_score += 5;
		}
		else if (add_score == 0)
		{
			add_score = 0;
			subtract_score = 0;
			add_flg = false;
			subtract_flg = false;
		}
		else
		{
			score += 5;
			add_score -= 5;
		}
	}
	else if (add_flg == true)
	{
		score += 5;
		add_score -= 5;

		if (add_score <= 0)
		{
			add_flg = false;
		}
	}
	else if (subtract_flg == true)
	{
		score -= 5;
		add_score += 5;

		if (add_score >= 0)
		{
			subtract_flg = false;
		}
	}
}

void Score::Draw() const
{
	// スコア描画
	SetFontSize(23);
	DrawFormatString(460, 23, 0xffffff,"SCORE:%07d",score);
}

void Score::FInalize()
{
}
