#include "InGameScene.h"
#include "../../Object/ReticleObject.h"
#include "../../Object/Enemy/Enemy.h"
#include "../../Object/Enemy1/Enemy1.h"
#include "../../Object/Enemy2/Enemy2.h"
#include "../../Object/Enemy3/Enemy3.h"


// コンストラクタ
InGameScene::InGameScene()
{
	CreateObject<ReticleObject>(Vector2D(0.0f, 0.0f));
	/*デバック用*/
	CreateObject<Enemy>(Vector2D((0.0f - 25.0f), 240.0f));
	CreateObject<Enemy1>(Vector2D((0.0f - 25.0f), 300.0f));
	CreateObject<Enemy2>(Vector2D((0.0f - 25.0f), 360.0f));
	CreateObject<Enemy3>(Vector2D((0.0f - 25.0f), 420.0f));
}

// デストラクタ
InGameScene::~InGameScene()
{
}

// 初期化処理
void InGameScene::Initialize()
{
	
}

// 更新処理
eSceneType InGameScene::Update()
{
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			// 当たり判定チェック処理
			HitCheckObject(objects[i], objects[j]);
		}
	}

	// オブジェクト削除処理
	Delete();

	// 範囲外オブジェクト削除処理
	ScreenOutDelete();

	return GetNowSceneType();	
}

// 描画処理
void InGameScene::Draw() const
{
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

// 終了時処理
void InGameScene::Finalize()
{
}

// 現在のシーン情報を返す
eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}

//画面外に行ったオブジェクトの削除処理
void InGameScene::ScreenOutDelete()
{
	for (int i = 0; i < objects.size(); i++)
	{
		// 画面外に行ったら削除する
		/*画面の右側の上限の値 900.0f	画面の左側の上限の値 - 400.0f*/
		if (objects[i]->GetLocation().x >= 900.0f || objects[i]->GetLocation().x < -400.0f)
		{
			objects.erase(objects.begin() + i);
		}		
	}
}

void InGameScene::Delete()
{
	for (int i = 0; i < objects.size(); i++)
	{
		//(削除のフラグがtrueのとき)
		if (objects[i]->DeleteFlag() == true)
		{
			objects.erase(objects.begin() + i);
		}
	}
}

#ifdef D_PIVOT
/// <summary>
/// 当たり判定チェック処理
/// </summary>
/// <param name="a">1つ目のゲームオブジェクト</param>
/// <param name="b">2つ目のゲームオブジェクト</param>
void InGameScene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
			a->OnHitCollision(b);
			b->OnHitCollision(a);
	}
}
#else
void InGameScene::HitCheckObject(GameObject* a, GameObject* b)
{

	// ヌルポチェック
	if (a == nullptr || b == nullptr)
	{
		return;
	}

	//右上頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT
