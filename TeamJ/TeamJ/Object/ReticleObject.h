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
	// ����������
	void Initialize() override;
	// �X�V����
	void Update() override;
	// �`�揈��
	void Draw() const override;
	// �I��������
	void Finalize() override;
	void HitCheck(void);
};

