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

	// �e�L�̈ړ�����ʒu
	direction = Vector2D(1.0f, 0.0f);

	// �i�s����
	location = Vector2D((0.0f - 50.0f), 240.0f);
}

void Enemy::Update()
{
	// �`�揈��
	Draw();

	// �ړ�����
	Movement();

	// �A�j���[�V��������

}

void Enemy::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��

	// �����l�p��`�悷��(�f�o�b�N�p)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	// �����l�p�̌��݂̈ʒu���
	DrawFormatString(20, 100, 0xffffff, "X���W %f Y���W %f", t1.x, br.y, TRUE);

	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();
}

void Enemy::Finalize()
{
	// �g�p�����摜���폜
}

void Enemy::Movement()
{
	// �ʒu���ɐi�s�����ɉ��Z
	location += direction;
}
