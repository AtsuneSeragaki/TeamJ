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

