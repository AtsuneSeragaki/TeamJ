#include "InGameScene.h"
#include "../../Object/ReticleObject.h"
#include "../../Object/Enemy/Enemy.h"
#include "../../Object/Enemy1/Enemy1.h"
#include "../../Object/Enemy2/Enemy2.h"
#include "../../Object/Enemy3/Enemy3.h"

// コンストラクタ
InGameScene::InGameScene()
{
	CreateObject<ReticleObject>(Vector2D(0.0f, 0.0f));
	/*デバック用*/
	CreateObject<Enemy>(Vector2D(0.0f, 0.0f));
	CreateObject<Enemy1>(Vector2D(0.0f, 0.0f));
	CreateObject<Enemy2>(Vector2D(0.0f, 0.0f));
	CreateObject<Enemy3>(Vector2D(0.0f, 0.0f));
}

// デストラクタ
InGameScene::~InGameScene()
{
}

// 初期化処理
void InGameScene::Initialize()
{
	
}

// 更新処理
eSceneType InGameScene::Update()
{
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	return GetNowSceneType();
}

// 描画処理
void InGameScene::Draw() const
{
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

// 終了時処理
void InGameScene::Finalize()
{
}

// 現在のシーン情報を返す
eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}
