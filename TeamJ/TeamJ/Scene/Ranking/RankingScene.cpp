#include "RankingScene.h"
#include <DxLib.h>

// コンストラクタ
RankingScene::RankingScene()
{
}

// デストラクタ
RankingScene::~RankingScene()
{
}

// 初期化処理
void RankingScene::Initialize()
{
	//仮の名前
	char handlename[5] = { 'maly','john','ken','roy','luke' };
}

// 更新処理
eSceneType RankingScene::Update()
{
	return GetNowSceneType();
}

// 描画処理
void RankingScene::Draw() const
{
	SetFontSize(20);
	DrawString(10, 10, "RANKING", 0xffffff);

	//SetFontSize(50);
	for (int i = 1; i < 6; ++i)
	{
		//DrawFormatString(50, 70 + i * 60, GetColor(255, 255, 255), "No.%d %4s %d", i, handlename[i - 1], 600 - (i * 100));
		DrawFormatString(50, 70 + i * 60, GetColor(255, 255, 255), "No.%d  %d", i, 600 - (i * i + 10 * i));
	}
}

// 終了時処理
void RankingScene::Finalize()
{
}

// 現在のシーン情報を返す
eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking;
}
