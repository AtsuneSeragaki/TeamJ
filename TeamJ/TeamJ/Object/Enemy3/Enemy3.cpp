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
/// 初期化処理
/// </summary>
void Enemy3::Initialize()
{
	// オブジェクトの種類を設定
	type = ENEMY3;

	// ボックスのサイズ(当たり判定の大きさ)
	box_size = Vector2D(25.0f, 75.0f);

	// テキの移動する位置
	direction = Vector2D(1.3f, 0.0f);

	// 進行方向
	//location = Vector2D((0.0f - 25.0f), 420.0f);

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int>tmp;
	tmp = rm->GetImages("Resource/Images/瓶3.png");
	image = tmp[0];

}

/// <summary>
/// 更新処理
/// </summary>
void Enemy3::Update()
{
	// 描画処理
	Draw();


	// 移動処理
	Movement();
}

/// <summary>
/// 描画処理
/// </summary>
void Enemy3::Draw() const
{
	// 画像反転グラフ

	// 進行方向によって反転状態を決定する

	// 敵画像を描画する

	// 白い四角を描画する(デバック用)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 0, 255), TRUE);
	DrawRotaGraphF(location.x, location.y, 0.08f, 0.0f, image, TRUE, FALSE);

	// 白い四角の現在の位置情報
	//DrawFormatString(20, 160, 0xffffff, "Enemy3X座標 %f Y座標 %f", t1.x, br.y, TRUE);

	//オブジェクトのタイプの種類を確認(デバッグ)
	//DrawFormatString(400, 160, 0xffffff, "このオブジェクトのtypeは%d", type, TRUE);


	// 親クラスの描画処理を呼び出す(当たり判定の目安)
	__super::Draw();
}

/// <summary>
/// 終了時処理
/// </summary>
void Enemy3::Finalize()
{
}

/// <summary>
/// 移動処理
/// </summary>
void Enemy3::Movement()
{
	// 位置情報に進行方向に加算
	location += direction;
}

/// <summary>
/// 範囲外削除処理(いらないかも)
/// </summary>
void Enemy3::ScreenDelete()
{
}

// 当たり判定通知処理
void Enemy3::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE && object->HitFlag() == true)
	{
		// 削除するFlagをTRUEにする
		delete_flg = true;
		is_break = true;
	}
}
