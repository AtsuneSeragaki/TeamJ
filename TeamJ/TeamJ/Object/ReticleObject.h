#pragma once

#include"GameObject.h"

class ReticleObject:public GameObject
{
private:

	Vector2D box2_size;
	bool push_flg;
	int bullet;
	int reload_cnt;
	int img[2];
	int sound[9];
	int ejection_cnt;

	int font_bullet;
	int font_loading;
	

public:
	// 初期化処理
	void Initialize() override;
	// 更新処理
	void Update() override;
	// 描画処理
	void Draw() const override;
	// 終了時処理
	void Finalize() override;
	void HitCheck(void);

private:
	void OnHitCollision(GameObject* object) override;
};

