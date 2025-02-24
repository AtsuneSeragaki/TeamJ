#include "EndScene.h"

// コンストラクタ
EndScene::EndScene():cnt(0)
{
}

// デストラクタ
EndScene::~EndScene()
{
}

// 初期化処理
void EndScene::Initialize()
{
	cnt = 180;
}

// 更新処理
eSceneType EndScene::Update()
{
	if (cnt > 0)
	{
		cnt--;
	}
	else
	{
		cnt = 0;
		return eSceneType::eNone;
	}
	

	return GetNowSceneType();
}

// 描画処理
void EndScene::Draw() const
{
}

// 終了時処理
void EndScene::Finalize()
{
}

// 現在のシーン情報を返す
eSceneType EndScene::GetNowSceneType() const
{
	return eSceneType::eEnd;
}
