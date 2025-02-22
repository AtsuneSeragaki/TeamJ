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
	tmp2 = rm->GetSounds("Resource/Sounds/拳銃を撃つ.mp3");
	sound[0] = tmp2;
	tmp2=rm->GetSounds("Resource/Sounds/排莢.mp3");
	sound[1] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/拳銃の弾切れ.mp3");
	sound[2] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/弾倉を外す.mp3");
	sound[3] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/弾倉をセット.mp3");
	sound[4] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/拳銃のスライドを引く.mp3"); 
	sound[5] = tmp2;
}

void ReticleObject::Update()
{
	InputManager* input = InputManager::GetInstance();

	//左スティックのx座標を加算
	if (input->GetLeftStick().x>=0.1f|| input->GetLeftStick().x <= -0.1f)
	{
		location.x += input->GetLeftStick().x * 7;
	}
	//左スティックのy座標を減算
	if (input->GetLeftStick().y >= 0.1f || input->GetLeftStick().y <= -0.1f)
	{
		location.y -= input->GetLeftStick().y * 7;
	}
	//左に出ないようにする
	if (location.x < 0.0f + box_size.x * 0.5f)
	{
		location.x = 0.0f + box_size.x * 0.5f;
	}
	//上に出ないようにする
	if (location.y < 0.0f + box_size.y * 0.5f)
	{
		location.y = 0.0f + box_size.y * 0.5f;
	}
	//右に出ないようにする
	if (location.x > 640.0f - box_size.x * 0.5f)
	{
		location.x = 640.0f - box_size.x * 0.5f;
	}
	//下に出ないようにする
	if (location.y > 480.0f - box_size.y * 0.5f)
	{
		location.y = 480.0f - box_size.y * 0.5f;
	}
	//Bボタンが押されたら撃つ
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
