#include "Enemy3.h"
#include "DxLib.h"
#include "../../Utility/ResourceManager.h"

Enemy3::Enemy3() : image(0)
{
}

Enemy3::~Enemy3()
{
}

/// <summary>
/// ����������
/// </summary>
void Enemy3::Initialize()
{
	// �I�u�W�F�N�g�̎�ނ�ݒ�
	type = ENEMY3;

	// �{�b�N�X�̃T�C�Y(�����蔻��̑傫��)
	box_size = Vector2D(25.0f, 75.0f);

	// �e�L�̈ړ�����ʒu
	direction = Vector2D(1.3f, 0.0f);

	// �i�s����
	//location = Vector2D((0.0f - 25.0f), 420.0f);

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/�r3.png");
	image = tmp[0];

}

/// <summary>
/// �X�V����
/// </summary>
void Enemy3::Update()
{
	// �`�揈��
	Draw();


	// �ړ�����
	Movement();
}

/// <summary>
/// �`�揈��
/// </summary>
void Enemy3::Draw() const
{
	// �摜���]�O���t

	// �i�s�����ɂ���Ĕ��]��Ԃ����肷��

	// �G�摜��`�悷��

	// �����l�p��`�悷��(�f�o�b�N�p)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 0, 255), TRUE);
	DrawRotaGraphF(location.x, location.y, 0.08f, 0.0f, image, TRUE, FALSE);

	// �����l�p�̌��݂̈ʒu���
	//DrawFormatString(20, 160, 0xffffff, "Enemy3X���W %f Y���W %f", t1.x, br.y, TRUE);

	//�I�u�W�F�N�g�̃^�C�v�̎�ނ��m�F(�f�o�b�O)
	//DrawFormatString(400, 160, 0xffffff, "���̃I�u�W�F�N�g��type��%d", type, TRUE);


	// �e�N���X�̕`�揈�����Ăяo��(�����蔻��̖ڈ�)
	__super::Draw();
}

/// <summary>
/// �I��������
/// </summary>
void Enemy3::Finalize()
{
}

/// <summary>
/// �ړ�����
/// </summary>
void Enemy3::Movement()
{
	// �ʒu���ɐi�s�����ɉ��Z
	location += direction;
}

/// <summary>
/// �͈͊O�폜����(����Ȃ�����)
/// </summary>
void Enemy3::ScreenDelete()
{
}

// �����蔻��ʒm����
void Enemy3::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE && object->HitFlag() == true)
	{
		// �폜����Flag��TRUE�ɂ���
		delete_flg = true;
		is_break = true;
	}
}
