#pragma once

#include "../GameObject.h"

class Enemy3 : public GameObject
{
	// int animation;				// �A�j���[�V�����摜
	// int animation_count;
	Vector2D direction;		// �i�s����

public:
	Enemy3();
	~Enemy3();

	virtual void Initialize() override;				//����������
	virtual void Update() override;					//�X�V����
	virtual void Draw() const override;				//�`�揈��
	virtual void Finalize() override;				//�I������


private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	// void AnimationControl();


	// �͈͊O�̃I�u�W�F�N�g���폜���鏈��
	void ScreenDelete();

	// �����蔻��ʒm����
	void OnHitCollision(GameObject* object) override;
};