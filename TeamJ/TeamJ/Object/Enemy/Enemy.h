#pragma once

#include "../GameObject.h"

class Enemy : public GameObject
{
private:
	int image;
	// int animation;				// アニメーション画像
	// int animation_count;
	Vector2D direction;		// 進行方向

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;				//初期化処理
	virtual void Update() override;					//更新処理
	virtual void Draw() const override;				//描画処理
	virtual void Finalize() override;				//終了処理


private:
	//移動処理
	void Movement();
	//アニメーション制御
	// void AnimationControl();

	
	// 範囲外のオブジェクトを削除する処理
	void ScreenDelete();

	void OnHitCollision(GameObject* object) override;
};