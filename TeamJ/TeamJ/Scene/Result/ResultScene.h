#pragma once

#include "../SceneBase.h"

#define BUTTON_WIDTH   100
#define BUTTON_HEIGHT  50

class ResultScene : public SceneBase
{
private:
	int menu_num;                   // 選択しているメニュー番号(0:リスタート 1:タイトル)
	std::vector<int> button_img;    // ボタン画像
	int background_img;             // 背景画像

	bool push_flg;
	int cnt;

	int sound[3];

	int font_scene_name;
	int font_result;
	int font_button;

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

};