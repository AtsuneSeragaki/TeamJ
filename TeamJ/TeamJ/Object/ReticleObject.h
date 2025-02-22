#pragma once

#include"GameObject.h"

class ReticleObject:public GameObject
{
private:

	bool push_flg;
	int bullet;
	int reload_cnt;
	int img;
	int sound[6];
	int ejection_cnt;

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
};

