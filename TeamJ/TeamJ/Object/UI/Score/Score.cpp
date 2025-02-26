#include "Score.h"
#include "DxLib.h"

int Score::score = 0;

Score::Score() : /*score(0),*/add_score(0),subtract_score(0),add_flg(false),subtract_flg(false),draw_add_score{},draw_subtract_score{},draw_add_score_cnt{},draw_subtract_score_cnt{},draw_add_score_pos{},draw_subtract_score_pos{}
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
	for (int i = 0; i < 50; i++)
	{
		draw_add_score[i] = 0;
		draw_subtract_score[i] = 0;
		draw_add_score_cnt[i] = -1;
		draw_subtract_score[i] = -1;
		draw_add_score_pos[i] = Vector2D(0.0f);
		draw_subtract_score_pos[i] = Vector2D(0.0f);
	}
	
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

	for (int i = 0; i < 50; i++)
	{
		if (draw_add_score_cnt[i] != -1)
		{
			draw_add_score_cnt[i]++;

			if (draw_add_score_cnt[i] >= 60)
			{
				draw_add_score_cnt[i] = -1;
				draw_add_score[i] = 0;
				draw_add_score_pos[i] = Vector2D(0.0f);
			}
		}

		if (draw_subtract_score_cnt[i] != -1)
		{
			draw_subtract_score_cnt[i]++;

			if (draw_subtract_score_cnt[i] >= 60)
			{
				draw_subtract_score_cnt[i] = -1;
				draw_subtract_score[i] = 0;
				draw_subtract_score_pos[i] = Vector2D(0.0f);
			}
		}
	}
}

void Score::Draw() const
{
	// スコア描画
	SetFontSize(23);
	DrawFormatString(460, 23, 0xffffff,"SCORE:%07d",score);

	for (int i = 0; i < 50; i++)
	{
		if (draw_add_score_cnt[i] != -1)
		{
		    DrawFormatString(draw_add_score_pos[i].x, draw_add_score_pos[i].y - 50.0f, 0xffffff, "+%d", draw_add_score[i]);
		}

		if (draw_subtract_score_cnt[i] != -1)
		{
			DrawFormatString(draw_subtract_score_pos[i].x, draw_subtract_score_pos[i].y - 50.0f, 0xffffff, "-%d", draw_subtract_score[i]);
		}
	}

}

void Score::FInalize()
{
}

void Score::AddScore(int point, Vector2D pos)
{
	add_score += point;

	for (int i = 0; i < 50; i++)
	{
		if (draw_add_score[i] == 0)
		{
			draw_add_score[i] = point;
			draw_add_score_cnt[i] = 0;
			draw_add_score_pos[i] = pos;

			return;
		}
	}	
}

void Score::SubtractScore(int point,Vector2D pos)
{ 
	subtract_score -= point; 

	for (int i = 0; i < 50; i++)
	{
		if (draw_subtract_score[i] == 0)
		{
			draw_subtract_score[i] = point;
			draw_subtract_score_cnt[i] = 0;
			draw_subtract_score_pos[i] = pos;

			return;
		}
	}
}