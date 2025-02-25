#pragma once

#include "../SceneBase.h"

class EndScene : public SceneBase
{
private:
	Vector2D location;

	int cnt;   // 終了までのカウント
	int bgm;
	int image;
	int sound;
	int font_button;

	bool push_flg;

public:
	// コンストラクタ
	EndScene();
	// デストラクタ
	~EndScene();

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