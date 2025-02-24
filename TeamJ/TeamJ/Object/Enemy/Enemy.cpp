#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

/// <summary>
/// 初期化処理
/// </summary>
void Enemy::Initialize()
{
	// オブジェクトの種類を設定
	type = ENEMY;

	// ボックスのサイズ(当たり判定の大きさ)
	box_size = 50.0f;

	// テキの移動する位置
	direction = Vector2D(1.0f, 0.0f);

	// 進行方向
	//location = Vector2D((0.0f - 25.0f), 240.0f);
}
/// <summary>
/// 更新処理
/// </summary>
void Enemy::Update()
{
	// 描画処理
	Draw();

	// 移動処理
	Movement();

	// アニメーション制御

	// if ()
	// {
	// 	// Xの座標が0の時、四角を削除する
	// }
	// if ()
	// {
	// 	// またはXの座標が640の時、四角を削除する
	// 
	// }

}

/// <summary>
/// 描画処理
/// </summary>
void Enemy::Draw() const
{
	// 画像反転グラフ

	// 進行方向によって反転状態を決定する

	// 敵画像を描画する

	// 白い四角を描画する(デバック用)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);

	// 白い四角の現在の位置情報(デバック)
	DrawFormatString(20, 100, 0xffffff, "EnmeyのX座標 %f Y座標 %f", t1.x, br.y, TRUE);

	//オブジェクトのタイプの種類を確認(デバッグ)
	DrawFormatString(400, 100, 0xffffff, "このオブジェクトのtypeは%d", type, TRUE);

	// 親クラスの描画処理を呼び出す(当たり判定の目安)
	__super::Draw();
}

/// <summary>
/// 終了時処理
/// </summary>
void Enemy::Finalize()
{
	// 使用した画像を削除
}

void Enemy::Movement()
{
	// 位置情報に進行方向に加算
	location += direction;
}

void Enemy::OnHitCollision(GameObject* object)
{
	if (object->GetType() == RETICLE && object->HitFlag() == true)
	{
		// 削除するフラグをtrueにする
		delete_flg = true;
	}
}

/// <summary>
/// 範囲外削除処理(いらないかも)
/// </summary>
void Enemy::ScreenDelete()
{

}
