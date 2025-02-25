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
	int sound[6];
	int ejection_cnt;

public:
	// ‰Šú‰»ˆ—
	void Initialize() override;
	// XVˆ—
	void Update() override;
	// •`‰æˆ—
	void Draw() const override;
	// I—¹ˆ—
	void Finalize() override;
	void HitCheck(void);
};

