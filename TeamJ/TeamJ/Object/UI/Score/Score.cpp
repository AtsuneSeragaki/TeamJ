#include "Score.h"
#include "DxLib.h"

Score::Score() : score(0)
{
}

Score::~Score()
{
}

void Score::Initialize()
{
	score = 0;
}

void Score::Update()
{
}

void Score::Draw() const
{
	// スコア描画
	DrawFormatString(500,32, 0xffffff, "score:%d", score);
}

void Score::FInalize()
{
}
