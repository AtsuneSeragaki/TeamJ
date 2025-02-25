#pragma once

#include "../SceneBase.h"
#define RANKING_DATA (5)

class RankingScene : public SceneBase
{
private:
	int score[RANKING_DATA];       //スコアデータ
	int rank[RANKING_DATA];        //ランクデータ
	int sound2[6];				   //効果音
	int button_image;			   //ボタンの画像
	int font_scene_name;		   //シーンのフォントサイズ
	int font_button;			   //ボタンのフォントサイズ
	int font_score;			       //スコアのフォントサイズ


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

	//ランキングの入れ替え
	void SetRank(int score);

public:
	// 現在のシーン情報を返す
	virtual eSceneType GetNowSceneType() const override;

};