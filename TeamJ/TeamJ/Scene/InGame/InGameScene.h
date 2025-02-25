#pragma once

#include "../SceneBase.h"

// ifdef用
#define D_PIVOT						// HitCeckObjectで使用
#define D_SPAWN						// SpawnEnemyで使用

// マクロ定義
#define D_MAX_SPAWN		(10)			// テキスポーンの最大数(デバック用)


class InGameScene : public SceneBase
{
private:

	int enemy_num;

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
	// 敵スポーン方法処理
	void SpawnEnemy();

	// 画面外に行ったオブジェクトの削除処理
	void ScreenOutDelete();

	// 削除処理(ReticleObjectの当たり判定にあたったら削除する)
	void Delete();

	// 当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);
};