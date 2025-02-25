#include "InGameScene.h"
#include "../../Object/ReticleObject.h"
#include "../../Object/Enemy/Enemy.h"
#include "../../Object/Enemy1/Enemy1.h"
#include "../../Object/Enemy2/Enemy2.h"
#include "../../Object/Enemy3/Enemy3.h"

// デバック用 一旦書き込んだだけ
#include "../../Utility/InputManager.h"
#include "DxLib.h"


// コンストラクタ
InGameScene::InGameScene() : enemy_num(0)
{
	CreateObject<ReticleObject>(Vector2D(0.0f, 0.0f));
	/*デバック用*/
	//CreateObject<Enemy>(Vector2D((0.0f - 25.0f), 240.0f));
	//CreateObject<Enemy1>(Vector2D((0.0f - 25.0f), 300.0f));
	//CreateObject<Enemy2>(Vector2D((0.0f - 25.0f), 360.0f));
	//CreateObject<Enemy3>(Vector2D((0.0f - 25.0f), 420.0f));
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

	// 敵生成処理
	SpawnEnemy();

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

// 敵生成処理
void InGameScene::SpawnEnemy()
{
#ifdef D_SPAWN		// if( ifdef == D_SPAWN )		defineはヘッダーにある
	int rd;						//乱数を取得する変数
	int e_spawn;				// 敵出現スイッチ

	e_spawn = GetRand(2);		// 0～2までのランダムな数字を取得する
	rd = GetRand(4);			// 100までのランダムな数字を出す

	if (enemy_num < D_MAX_SPAWN)
	{
		if (rd == 3)
		{
			switch (e_spawn)
			{
				// 一番上の段 一レーンに的野和生成する
			case 0:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 真ん中の段
			case 1:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
			case 2:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
			}
		}
		if (rd == 2)
		{
			switch (e_spawn)
			{
				// 一番上の段
			case 0:
				CreateObject<Enemy1>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 真ん中の段
			case 1:
				CreateObject<Enemy1>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 一番下の段
			case 2:
				CreateObject<Enemy1>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
			}

		}
		if (rd == 1)
		{
			switch (e_spawn)
			{
				// 一番上の段
			case 0:
				CreateObject<Enemy2>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 真ん中の段
			case 1:
				CreateObject<Enemy2>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 一番下の段
			case 2:
				CreateObject<Enemy2>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
			}
		}
		if (rd == 0)
		{
			switch (e_spawn)
			{
				// 一番上の段
			case 0:
				CreateObject<Enemy3>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 真ん中の段
			case 1:
				CreateObject<Enemy3>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
				// 一番下の段
			case 2:
				CreateObject<Enemy3>(Vector2D(-25.0f, 100.0f + (80 + (100 * e_spawn))));
				enemy_num++;
				break;
			}
		}
	}

#else
	InputManager* input = InputManager::GetInstance();
	if (input->GetKeyInputState(KEY_INPUT_SPACE) == eInputState::ePress)
	{
		int a;
		a = GetRand(2);
		//CreateObject<Enemy>(Vector2D((0.0f - 25.0f), 240.0f));
		if (enemy_num < D_MAX_SPAWN)
		{
			switch (a)
			{
			case 0:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * a))));
				enemy_num++;
				break;
			case 1:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * a))));
				enemy_num++;
				break;
			case 2:
				CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * a))));
				enemy_num++;
				break;
				//case 3:
				//	CreateObject<Enemy>(Vector2D(-25.0f, 100.0f + (80 + (100 * a))));
				break;
			default:
				break;
			}

		}

	}
	DrawFormatString(320, 340, 0xffffff, "%d", enemy_num, TRUE);
#endif // D_SPAWN
}

//画面外に行ったオブジェクトの削除処理
void InGameScene::ScreenOutDelete()
{
	for (int i = 0; i < objects.size(); i++)
	{
		// 画面外に行ったら削除する
		/*画面の右側の上限の値 900.0f	画面の左側の上限の値 - 400.0f*/
		if (objects[i]->GetLocation().x >= 800.0f || objects[i]->GetLocation().x < -400.0f)
		{
			objects.erase(objects.begin() + i);
			enemy_num--;
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
			if (objects[i]->IsBreak() == true)
			{
				objects.erase(objects.begin() + i);
				enemy_num--;
			}
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
