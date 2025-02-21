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

	direction = Vector2D(1.0f, 0.0f);

	location = Vector2D(0.0f, 0.0f);
}

void Enemy::Update()
{
	// 描画処理
	Draw();

	// 移動処理
	//Movement();

	// アニメーション制御

}

void Enemy::Draw() const
{
	// 画像反転グラフ

	// 進行方向によって反転状態を決定する

	// 敵画像を描画する
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);
	//DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 255, 255), TRUE);
	DrawBoxAA(0,0,10,10, GetColor(255, 255, 255), TRUE);
	// DrawBoxAA(470,0,10,10, GetColor(255, 255, 255), TRUE);

	// 親クラスの描画処理を呼び出す(当たり判定の目安)
	__super::Draw();
}

void Enemy::Finalize()
{
	// 使用した画像を削除
}

void Enemy::Movement()
{
	location += direction;
}
