#pragma once

#include "../SceneBase.h"

#define BUTTON_WIDTH   100
#define BUTTON_HEIGHT  50

#define PI    3.1415926535897932384626433832795f

class ResultScene : public SceneBase
{
private:
	int menu_num;                   // 選択しているメニュー番号(0:リスタート 1:タイトル)
	std::vector<int> button_img;    // ボタン画像

	bool push_flg;
	int cnt;

	int sound[3];

	int font_scene_name;
	int font_result;
	int font_button;
	int font_rank;

	int rank;
	int rank_cnt;

	int score;
	int score_display;

public:
	// コンストラクタ
	ResultScene();
	// デストラクタ
	~ResultScene();

public:
	// 初期化処理
	virtual void Initialize() override;
	// 更新処理
	virtual eSceneType Update() override;
	// 描画処理
	virtual void Draw() const override;
	// 終了時処理
	virtual void Finalize() override;

public:
	// 現在のシーン情報を返す
	virtual eSceneType GetNowSceneType() const override;

	// ランク透明度変更
	void ChangeRankBlendParam();

	// 表示するスコアの値を増やす
	void AddDisplayScore();
};