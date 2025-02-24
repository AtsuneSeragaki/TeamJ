#pragma once

#include "../SceneBase.h"

#define D_PIVOT

class InGameScene : public SceneBase
{
private:



public:
	// コンストラクタ
	InGameScene();
	// デストラクタ
	~InGameScene();

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

private:
	// 画面外に行ったオブジェクトの削除処理
	void ScreenOutDelete();

	// 削除処理(ReticleObjectの当たり判定にあたったら削除する)
	void Delete();

	// 当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);
};