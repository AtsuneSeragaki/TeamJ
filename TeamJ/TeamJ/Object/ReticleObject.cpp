#include "DxLib.h"
#include "ReticleObject.h"
#include "../Utility/InputManager.h"
#include "../Utility/ResourceManager.h"

#define PI    3.1415926535897932384626433832795f

void ReticleObject::Initialize()
{
	/******************************************************/
	//type = オブジェクトの種類の名前
	type = RETICLE;
	/******************************************************/
	location = Vector2D(320.0f, 240.0f);
	box_size = Vector2D(40.0f, 40.0f);
	box2_size = Vector2D(60.0f, 60.0f);
	push_flg = false;
	bullet = BULLET_MAX_NUN;
	ejection_cnt = 0;
	reload_cnt = 0;

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/reticle.png");
	img[0] = tmp[0];
	tmp = rm->GetImages("Resource/Images/bullet.png");
	img[1] = tmp[0];

	int tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/gun_shot.mp3");
	sound[0] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/ejection.mp3");
	sound[1] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/out_of_bullets.mp3");
	sound[2] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/reload.mp3");
	sound[3] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/reload2.mp3");
	sound[4] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/gun_slide.mp3");
	sound[5] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/beep.mp3");
	sound[6] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/bottle1.mp3");
	sound[7] = tmp2;
	tmp2 = rm->GetSounds("Resource/Sounds/bottle2.mp3");
	sound[8] = tmp2;

	ChangeVolumeSoundMem(130, sound[0]);
	ChangeVolumeSoundMem(130, sound[1]);

	font_bullet = CreateFontToHandle("Stencil", 20, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	font_loading = CreateFontToHandle("Stencil", 60, -1, DX_FONTTYPE_ANTIALIASING_4X4);

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
		hit_flg = true;
		bullet--;
		ejection_cnt++;
		PlaySoundMem(sound[0], DX_PLAYTYPE_BACK, TRUE);
		if (ejection_cnt <= 60)
		{
			PlaySoundMem(sound[1], DX_PLAYTYPE_BACK, TRUE);
			ejection_cnt = 0;
		}

		PlaySoundMem(sound[6], DX_PLAYTYPE_BACK, TRUE);
		
	}
	else
	{
		push_flg = false;
		hit_flg = false;
	}
	/*if (input->GetButtonUp(XINPUT_BUTTON_B))
	{
		push_flg = false;
		hit_flg = false;
	}*/

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
	//DrawBoxAA(location.x-box_size.x*0.5f,location.y-box_size.y*0.5f, location.x + box_size.x * 0.5f, location.y + box_size.y * 0.5f, 0xffffff, TRUE);
	//DrawString(0, 0, "a", 0xffffff);
	//DrawFormatString(0, 30, 0xffffff, "%f %f", location.x, location.y);

	DrawRotaGraphF(location.x, location.y, 1.0f, 0.0f, img[0], TRUE, FALSE);

	//DrawBoxAA(580 - box2_size.x * 0.5f, 420 - box2_size.y * 0.5f, 580 + box2_size.x * 0.5f, 420 + box2_size.y * 0.5f, 0xffffff, TRUE);
	DrawRotaGraphF(560, 420, 0.1f, PI / 180 * 90, img[1], TRUE, FALSE);
	DrawFormatStringToHandle(575, 420, 0xffffff, font_bullet, "×%d", bullet);

	// ろー
	if (reload_cnt != 0)
	{
		DrawStringToHandle(125, 175, "Now Loading...", 0x000000, font_loading);
		DrawStringToHandle(120, 170, "Now Loading...", 0xffffff, font_loading);
	}

	//DrawStringToHandle(120, 200, "Now Loading...", 0xffffff, font_loading);
}

void ReticleObject::Finalize()
{
	
}

void ReticleObject::HitCheck(void)
{
	
}

void ReticleObject::OnHitCollision(GameObject* object)
{
	if (hit_flg == true)
	{
		StopSoundMem(sound[6]);
		if(object->GetType()==ENEMY3)
		{
			PlaySoundMem(sound[7], DX_PLAYTYPE_BACK, TRUE);
		}
		else
		{
			PlaySoundMem(sound[8], DX_PLAYTYPE_BACK, TRUE);
		}
	}
}
