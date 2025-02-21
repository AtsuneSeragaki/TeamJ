#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

/// <summary>
/// ����������
/// </summary>
void Enemy::Initialize()
{
	// �{�b�N�X�̃T�C�Y(�����蔻��̑傫��)
	box_size = 100.0f;

	direction = Vector2D(1.0f, 0.0f);

	location = Vector2D(0.0f, 0.0f);
}

void Enemy::Update()
{
	// �`�揈��
	Draw();

	// �ړ�����
	//Movement();

	// �A�j���[�V��������

}

void Enemy::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	DrawBoxAA(0,0,10,10, GetColor(255, 255, 255), TRUE);
	// DrawBoxAA(470,0,10,10, GetColor(255, 255, 255), TRUE);

	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();
}

void Enemy::Finalize()
{
	// �g�p�����摜���폜
}

void Enemy::Movement()
{
	location += direction;
}
