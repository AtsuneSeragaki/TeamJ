#pragma once

#include <vector>

#define BAR_X        60.0f
#define BAR_Y        19.0f
#define BAR_WIDTH    300.0f
#define BAR_HEIGHT   22.0f

class Time
{
private:
	int cnt;              // １秒をカウントするための変数
	int time;             // 時間
	float bar_width;      // バーの幅
	float bar_height;     // バーの高さ
	std::vector<int> img; // バーの画像

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

public:
	// 時間を取得
	int GetCount() { return cnt; }

};