#include "DxLib.h"
#include "ReticleObject.h"
#include "../Utility/InputManager.h"
#include "../Utility/ResourceManager.h"

void ReticleObject::Initialize()
{
	location = Vector2D(320.0f, 240.0f);

	box_size = Vector2D(40.0f, 40.0f);

	push_flg = false;

	bullet = BULLET_MAX_NUN;

	ejection_cnt = 0;

	reload_cnt = 0;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/reticle.png");
	img = tmp[0];

	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/���e������.mp3");
	sound[0] = tmp2;
	tmp2=rm->GetSounds("Resource/Sounds/�r�.mp3");
	sound[1] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/���e�̒e�؂�.mp3");
	sound[2] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/�e�q���O��.mp3");
	sound[3] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/�e�q���Z�b�g.mp3");
	sound[4] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/���e�̃X���C�h������.mp3"); 
	sound[5] = tmp2;
}

void ReticleObject::Update()
{
	InputManager* input = InputManager::GetInstance();

	//���X�e�B�b�N��x���W�����Z
	if (input->GetLeftStick().x>=0.1f|| input->GetLeftStick().x <= -0.1f)
	{
		location.x += input->GetLeftStick().x * 7;
	}
	//���X�e�B�b�N��y���W�����Z
	if (input->GetLeftStick().y >= 0.1f || input->GetLeftStick().y <= -0.1f)
	{
		location.y -= input->GetLeftStick().y * 7;
	}
	//���ɏo�Ȃ��悤�ɂ���
	if (location.x < 0.0f + box_size.x * 0.5f)
	{
		location.x = 0.0f + box_size.x * 0.5f;
	}
	//��ɏo�Ȃ��悤�ɂ���
	if (location.y < 0.0f + box_size.y * 0.5f)
	{
		location.y = 0.0f + box_size.y * 0.5f;
	}
	//�E�ɏo�Ȃ��悤�ɂ���
	if (location.x > 640.0f - box_size.x * 0.5f)
	{
		location.x = 640.0f - box_size.x * 0.5f;
	}
	//���ɏo�Ȃ��悤�ɂ���
	if (location.y > 480.0f - box_size.y * 0.5f)
	{
		location.y = 480.0f - box_size.y * 0.5f;
	}
	//B�{�^���������ꂽ�猂��
	if (input->GetButtonDown(XINPUT_BUTTON_B)&&bullet>0)
	{
		push_flg = true;
		bullet--;
		ejection_cnt++;
		PlaySoundMem(sound[0], DX_PLAYTYPE_BACK, TRUE);
		if (ejection_cnt <= 60)
		{
			PlaySoundMem(sound[1], DX_PLAYTYPE_BACK, TRUE);
			ejection_cnt = 0;
		}
	}
	if (input->GetButtonUp(XINPUT_BUTTON_B))
	{
		push_flg = false;
	}

	if (bullet <= 0)
	{
		reload_cnt++;
		if (reload_cnt == 30)
		{
			PlaySoundMem(sound[3], DX_PLAYTYPE_BACK, TRUE);
		}
		if (reload_cnt == 60)
		{
			PlaySoundMem(sound[4], DX_PLAYTYPE_BACK, TRUE);
		}
		if (reload_cnt == 90)
		{
			PlaySoundMem(sound[5], DX_PLAYTYPE_BACK, TRUE);
		}
		if (reload_cnt >= 90)
		{
			bullet = BULLET_MAX_NUN;
			reload_cnt = 0;
		}
	}

	HitCheck();
}

void ReticleObject::Draw() const
{
	DrawBoxAA(location.x-box_size.x*0.5f,location.y-box_size.y*0.5f, location.x + box_size.x * 0.5f, location.y + box_size.y * 0.5f, 0xffffff, TRUE);
	DrawString(0, 0, "a", 0xffffff);
	DrawFormatString(0, 30, 0xffffff, "%f %f", location.x, location.y);

	DrawFormatString(0, 50, 0xffffff, "%d", bullet);

	DrawRotaGraphF(location.x, location.y,1.0f,0.0f, img, TRUE,FALSE);
}

void ReticleObject::Finalize()
{
	
}

void ReticleObject::HitCheck(void)
{
	
}
