#pragma once

class Score
{
private:
	int score; // スコア

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
	int GetScore() { return score; }
	// スコア加算処理（引数:加算する数）
	void AddScore(int point) { score += point; }
	// スコア減算処理（引数:減算する数）
	void SubtractScore(int point) { score -= point; }
};