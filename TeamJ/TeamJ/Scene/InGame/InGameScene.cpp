#include "InGameScene.h"
#include "../../Object/ReticleObject.h"

// コンストラクタ
InGameScene::InGameScene()
{
	CreateObject<ReticleObject>(Vector2D(0.0f, 0.0f));
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
