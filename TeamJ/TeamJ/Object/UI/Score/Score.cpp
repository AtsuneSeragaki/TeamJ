#include "Score.h"
#include "DxLib.h"

int Score::score = 0;

Score::Score() : /*score(0),*/add_score(0),subtract_score(0),add_flg(false),subtract_flg(false),draw_add_score{},draw_subtract_score{},draw_add_score_cnt{},draw_subtract_score_cnt{},draw_add_score_pos{},draw_subtract_score_pos{},font_score(0),font_score2(0)
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

	font_score = CreateFontToHandle("Stencil", 23, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_score2 = CreateFontToHandle("Stencil", 23, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	
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

			if (draw_add_score_cnt[i] >= 30)
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
	//DrawFormatString(460, 23, 0xffffff,"SCORE:%07d",score);
	if (score >= 999999)
	{
		DrawStringToHandle(460, 21, "SCORE : 999999", 0xfdddcb, font_score);
	}
	else
	{
		DrawFormatStringToHandle(460, 21, 0xfdddcb, font_score, "SCORE : %06d", score);
	}
	

	for (int i = 0; i < 50; i++)
	{
		if (draw_add_score_cnt[i] != -1)
		{
			if (draw_add_score_pos[i].y - 50.0f <= 0.0f)
			{
				DrawFormatStringToHandle(draw_add_score_pos[i].x, 5.0f, 0xfdddcb, font_score, "+%d", draw_add_score[i]);
			}
			else
			{
				DrawFormatStringToHandle(draw_add_score_pos[i].x, draw_add_score_pos[i].y - 50.0f, 0xfdddcb, font_score, "+%d", draw_add_score[i]);
			}
		}

		if (draw_subtract_score_cnt[i] != -1)
		{
			DrawFormatStringToHandle(draw_subtract_score_pos[i].x, draw_subtract_score_pos[i].y - 50.0f, 0xfdddcb, font_score, "-%d", draw_subtract_score[i]);
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