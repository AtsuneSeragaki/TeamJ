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
	// �I�u�W�F�N�g�̎�ނ�ݒ�
	type = ENEMY;

	// �{�b�N�X�̃T�C�Y(�����蔻��̑傫��)
	box_size = 50.0f;

	// �e�L�̈ړ�����ʒu
	direction = Vector2D(1.0f, 0.0f);

	// �i�s����
	//location = Vector2D((0.0f - 25.0f), 240.0f);
}
/// <summary>
/// �X�V����
/// </summary>
void Enemy::Update()
{
	// �`�揈��
	Draw();

	// �ړ�����
	Movement();

	// �A�j���[�V��������

	// if ()
	// {
	// 	// X�̍��W��0�̎��A�l�p���폜����
	// }
	// if ()
	// {
	// 	// �܂���X�̍��W��640�̎��A�l�p���폜����
	// 
	// }

}

/// <summary>
/// �`�揈��
/// </summary>
void Enemy::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��

	// �����l�p��`�悷��(�f�o�b�N�p)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);

	// �����l�p�̌��݂̈ʒu���(�f�o�b�N)
	DrawFormatString(20, 100, 0xffffff, "Enmey��X���W %f Y���W %f", t1.x, br.y, TRUE);

	//�I�u�W�F�N�g�̃^�C�v�̎�ނ��m�F(�f�o�b�O)
	DrawFormatString(400, 100, 0xffffff, "���̃I�u�W�F�N�g��type��%d", type, TRUE);

	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();
}

/// <summary>
/// �I��������
/// </summary>
void Enemy::Finalize()
{
	// �g�p�����摜���폜
}

void Enemy::Movement()
{
	// �ʒu���ɐi�s�����ɉ��Z
	location += direction;
}

void Enemy::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE && object->HitFlag() == true)
	{
		// �폜����t���O��true�ɂ���
		delete_flg = true;
	}
}

/// <summary>
/// �͈͊O�폜����(����Ȃ�����)
/// </summary>
void Enemy::ScreenDelete()
{

}
