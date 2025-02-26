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

	

public:
	// ����������
	void Initialize() override;
	// �X�V����
	void Update() override;
	// �`�揈��
	void Draw() const override;
	// �I��������
	void Finalize() override;
	void HitCheck(void);

private:
	void OnHitCollision(GameObject* object) override;
};

