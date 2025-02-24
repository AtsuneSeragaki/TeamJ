#include "Enemy1.h"
#include "DxLib.h"

Enemy1::Enemy1()
{
}

Enemy1::~Enemy1()
{
}

/// <summary>
/// ����������
/// </summary>
void Enemy1::Initialize()
{
	// �I�u�W�F�N�g�̎�ނ�ݒ�
	type = ENEMY1;

	// �{�b�N�X�̃T�C�Y(�����蔻��̑傫��)
	box_size = 50.0f;

	// �e�L�̈ړ�����ʒu
	direction = Vector2D(1.5f, 0.0f);

	// �i�s����
	//location = Vector2D((0.0f - 25.0f), 300.0f);
}

/// <summary>
/// �X�V����
/// </summary>
void Enemy1::Update()
{
	// �`�揈��
	Draw();

	// �ړ�����
	Movement();

}

/// <summary>
/// �`�揈��
/// </summary>
void Enemy1::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��

	// �����l�p��`�悷��(�f�o�b�N�p)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(0, 255, 255), TRUE);

	// �����l�p�̌��݂̈ʒu���
	DrawFormatString(20, 120, 0xffffff, "Enemy1X���W %f Y���W %f", t1.x, br.y, TRUE);

	//�I�u�W�F�N�g�̃^�C�v�̎�ނ��m�F(�f�o�b�O)
	DrawFormatString(400, 120, 0xffffff, "���̃I�u�W�F�N�g��type��%d", type, TRUE);


	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();

}

/// <summary>
/// �I��������
/// </summary>
void Enemy1::Finalize()
{
	// �g�p�����摜���폜
}

/// <summary>
/// �ړ�����
/// </summary>
void Enemy1::Movement()
{
	// �ʒu���ɐi�s�����ɉ��Z
	location += direction;

}

/// <summary>
/// �͈͊O�폜����(����Ȃ�����)
/// </summary>
void Enemy1::ScreenDelete()
{

}

void Enemy1::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE)
	{
		// �폜����Flag��TRUE�ɂ���
		delete_flg = true;
	}
}
