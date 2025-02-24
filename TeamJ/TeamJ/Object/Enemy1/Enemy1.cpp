#include "Enemy1.h"
#include "DxLib.h"

Enemy1::Enemy1()
{
}

Enemy1::~Enemy1()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Enemy1::Initialize()
{
	// オブジェクトの種類を設定
	type = ENEMY1;

	// ボックスのサイズ(当たり判定の大きさ)
	box_size = 50.0f;

	// テキの移動する位置
	direction = Vector2D(1.5f, 0.0f);

	// 進行方向
	//location = Vector2D((0.0f - 25.0f), 300.0f);
}

/// <summary>
/// 更新処理
/// </summary>
void Enemy1::Update()
{
	// 描画処理
	Draw();

	// 移動処理
	Movement();

}

/// <summary>
/// 描画処理
/// </summary>
void Enemy1::Draw() const
{
	// 画像反転グラフ

	// 進行方向によって反転状態を決定する

	// 敵画像を描画する

	// 白い四角を描画する(デバック用)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(0, 255, 255), TRUE);

	// 白い四角の現在の位置情報
	DrawFormatString(20, 120, 0xffffff, "Enemy1X座標 %f Y座標 %f", t1.x, br.y, TRUE);

	//オブジェクトのタイプの種類を確認(デバッグ)
	DrawFormatString(400, 120, 0xffffff, "このオブジェクトのtypeは%d", type, TRUE);


	// 親クラスの描画処理を呼び出す(当たり判定の目安)
	__super::Draw();

}

/// <summary>
/// 終了時処理
/// </summary>
void Enemy1::Finalize()
{
	// 使用した画像を削除
}

/// <summary>
/// 移動処理
/// </summary>
void Enemy1::Movement()
{
	// 位置情報に進行方向に加算
	location += direction;

}

/// <summary>
/// 範囲外削除処理(いらないかも)
/// </summary>
void Enemy1::ScreenDelete()
{

}

void Enemy1::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE)
	{
		// 削除するFlagをTRUEにする
		delete_flg = true;
	}
}
