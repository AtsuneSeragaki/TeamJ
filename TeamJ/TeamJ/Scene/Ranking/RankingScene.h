#pragma once

#include "../SceneBase.h"

class RankingScene : public SceneBase
{
private:
	int score[6];       //スコアデータ
	int rank[6];        //ランクデータ
	char name[6][15];   //名前データ
	char handlename[5];   //名前データ(仮)

public:
	// コンストラクタ
	RankingScene();
	// デストラクタ
	~RankingScene();

public:
	// 初期化処理
	virtual void Initialize() override;
	// 更新処理
	virtual eSceneType Update() override;
	// 描画処理
	virtual void Draw() const override;
	// 終了時処理
	virtual void Finalize() override;

private:
	//データ入れ替え処理
	void SortData();

public:
	// 現在のシーン情報を返す
	virtual eSceneType GetNowSceneType() const override;

};