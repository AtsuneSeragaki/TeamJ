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
	// ボックスのサイズ(当たり判定の大きさ)
	box_size = 100.0f;

	// テキの移動する位置
	direction = Vector2D(1.0f, 0.0f);

	// 進行方向
	location = Vector2D((0.0f - 50.0f), 240.0f);
}

void Enemy::Update()
{
	// 描画処理
	Draw();

	// 移動処理
	Movement();

	// アニメーション制御

}

void Enemy::Draw() const
{
	// 画像反転グラフ

	// 進行方向によって反転状態を決定する

	// 敵画像を描画する

	// 白い四角を描画する(デバック用)
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	// 白い四角の現在の位置情報
	DrawFormatString(20, 100, 0xffffff, "X座標 %f Y座標 %f", t1.x, br.y, TRUE);

	// 親クラスの描画処理を呼び出す(当たり判定の目安)
	__super::Draw();
}

void Enemy::Finalize()
{
	// 使用した画像を削除
}

void Enemy::Movement()
{
	// 位置情報に進行方向に加算
	location += direction;
}
