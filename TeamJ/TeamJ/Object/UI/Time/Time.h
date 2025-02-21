#pragma once

class Time
{
private:
	int cnt;        // １秒をカウントするための変数
	int time;       // 時間
	int bar_width;  // バーの幅
	int bar_height; // バーの高さ

public:
	// コンストラクタ
	Time();
	// デストラクタ
	~Time();

public:
	// 初期化処理
	void Initialize();
	// 更新処理
	void Update();
	// 描画処理
	void Draw() const;
	// 終了時処理
	void FInalize();

};