#pragma once

#include "../../../Utility/Vector2D.h"

class Score
{
private:
	//int score; // スコア

	int add_score;
	int subtract_score;
	int add_flg;
	int subtract_flg;
	int draw_add_score[50];
	int draw_subtract_score[50];
	int draw_add_score_cnt[50];
	int draw_subtract_score_cnt[50];
	Vector2D draw_add_score_pos[50];
	Vector2D draw_subtract_score_pos[50];

	int font_score;
	int font_score2;

public:
	static int score; // スコア

public:
	// コンストラクタ
	Score();
	// デストラクタ
	~Score();

public:
	// 初期化処理
	void Initialize();
	// 更新処理
	void Update();
	// 描画処理
	void Draw() const;
	// 終了時処理
	void FInalize();

public:
	// スコア取得処理
	//int GetScore() { return score; }
	// スコア加算処理（引数:加算する数）
	void AddScore(int point,Vector2D pos);
	// スコア減算処理（引数:減算する数）
	void SubtractScore(int point,Vector2D pos);
};