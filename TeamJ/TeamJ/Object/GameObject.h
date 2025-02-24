#pragma once

#include "../Utility/Vector2D.h"
#define BULLET_MAX_NUN 5

enum ObjectType
{
	RETICLE,
	ENEMY,
	ENEMY1,
	ENEMY2,
	ENEMY3,
};

class GameObject
{
protected:
	Vector2D location;   // 座標
	Vector2D box_size;   // 当たり判定
	int graphic_images;  // オブジェクト画像
	int flip_flag;       // 反転するか？
	ObjectType type;	 // オブジェクトの種類の判別
	bool delete_flg;	// 削除フラグ
	bool hit_flg;		// 当たり判定フラグ

public:
	GameObject();
	virtual ~GameObject();

public:
	// 初期化処理
	virtual void Initialize();
	// 更新処理
	virtual void Update();
	// 描画処理
	virtual void Draw() const;
	// 終了時処理
	virtual void Finalize();

public:
	// 座標を返す
	const Vector2D& GetLocation() const
	{
		return location;
	}
	// 座標を設定する
	void SetLocation(const Vector2D& location)
	{
		this->location = location;
	}
	// 当たり判定の範囲を返す
	const Vector2D& GetBoxSize() const
	{
		return box_size;
	}
	// オブジェクトのタイプを判別する処理
	int GetType()
	{
		return this->type;
	}
	// 削除フラグ
	bool DeleteFlag()
	{
		return this->delete_flg;
	}

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="object">1つ目のゲームオブジェクト</param>
	virtual void OnHitCollision(GameObject* object);
};