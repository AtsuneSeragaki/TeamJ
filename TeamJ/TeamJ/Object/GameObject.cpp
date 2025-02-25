#include "GameObject.h"
#include "DxLib.h"

GameObject::GameObject() : location(0.0f), box_size(0.0f), graphic_images(NULL), flip_flag(FALSE), type(RETICLE), delete_flg(false), hit_flg(false), is_break(false)
{

}

GameObject::~GameObject()
{
	this->Finalize();
}

void GameObject::Initialize()
{
}

void GameObject::Update()
{

}

void GameObject::Draw() const
{
	// オブジェクト画像を描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, graphic_images, TRUE, flip_flag);

#if _DEBUG
	// 当たり判定の範囲を描画
	Vector2D a = location - (box_size * 0.5f);
	Vector2D b = a + box_size;
	DrawBoxAA(a.x, a.y, b.x, b.y, GetColor(0, 255, 0), FALSE);
#endif // _DEBUG
}

void GameObject::Finalize()
{
}

// 当たり判定通知処理
void GameObject::OnHitCollision(GameObject* object)
{
	// 当たったときに行う処理をGameObjectを継承したクラスのこの関数【OnHitCollision(GameObject* object)】に書く
}

