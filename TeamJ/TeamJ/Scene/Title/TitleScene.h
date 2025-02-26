#pragma once

#include "../SceneBase.h"

class TitleScene : public SceneBase
{

private:
	int menu_num;

	Vector2D location2;
	Vector2D location3;
	Vector2D location4;
	Vector2D box2_size;
	Vector2D box3_size;
	Vector2D box4_size;

	bool push_flg;
	int cnt;

	int image[2];

	int sound2[6];

	int font_scene_name;
	int font_button;

	int bgm;
	bool play_bgm; 

public:
	// コンストラクタ
	TitleScene();
	// デストラクタ
	~TitleScene();

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