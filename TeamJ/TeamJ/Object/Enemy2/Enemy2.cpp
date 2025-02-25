#include "Enemy2.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"
Enemy2::Enemy2() : image(0)
{
}

Enemy2::~Enemy2()
{
}

/// <summary>
/// ����������
/// </summary>
void Enemy2::Initialize()
{
	// �I�u�W�F�N�g�̎�ނ�ݒ�
	type = ENEMY2;

	// �{�b�N�X�̃T�C�Y(�����蔻��̑傫��)
	box_size = 50.0f;

	// �e�L�̈ړ�����ʒu
	direction = Vector2D(2.0f, 0.0f);

	// �i�s����
	//location = Vector2D((0.0f - 25.0f), 360.0f);
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/�r3.png");
	image = tmp[0];

}

/// <summary>
/// �X�V����
/// </summary>
void Enemy2::Update()
{
	// �`�揈��
	Draw();

	// �ړ�����
	Movement();
}

/// <summary>
/// �`�揈��
/// </summary>
void Enemy2::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��

	// �����l�p��`�悷��(�f�o�b�N�p)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(0, 0, 255), TRUE);
	DrawRotaGraphF(location.x, location.y, 0.05f, 0.0f, image, TRUE, FALSE);

	// �����l�p�̌��݂̈ʒu���
	DrawFormatString(20, 140, 0xffffff, "Enemy2X���W %f Y���W %f", t1.x, br.y, TRUE);

	//�I�u�W�F�N�g�̃^�C�v�̎�ނ��m�F(�f�o�b�O)
	DrawFormatString(400, 140, 0xffffff, "���̃I�u�W�F�N�g��type��%d", type, TRUE);


	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();

}

/// <summary>
/// �I��������
/// </summary>
void Enemy2::Finalize()
{

}

/// <summary>
/// �ړ�����
/// </summary>
void Enemy2::Movement()
{
	// �ʒu���ɐi�s�����ɉ��Z
	location += direction;
}

/// <summary>
/// �͈͊O�폜����(����Ȃ�����)
/// </summary>
void Enemy2::ScreenDelete()
{

}

void Enemy2::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE && object->HitFlag() == true)
	{
		// �폜����Flag��TRUE�ɂ���
		delete_flg = true;
		is_break = true;
	}

}
