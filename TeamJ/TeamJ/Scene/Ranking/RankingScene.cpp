#include "RankingScene.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"

// コンストラクタ
RankingScene::RankingScene():score{},rank{}
{
}

// デストラクタ
RankingScene::~RankingScene()
{
}

// 初期化処理
void RankingScene::Initialize()
{
    //音源の読み込み
    ResourceManager* rm = ResourceManager::GetInstance();
    std::vector<int>tmp;
    tmp = rm->GetImages("Resource/Images/Title.png");
    background_image = tmp[0];
    int tmp2;
    tmp2 = rm->GetSounds("Resource/Sounds/gun_shot.mp3");
    sound2[0] = tmp2;
    tmp2 = rm->GetSounds("Resource/Sounds/cursor_sound.mp3");
    sound2[1] = tmp2;
	
    // ランキングデータの読み込み
    FILE* fp = nullptr;

    // ファイルオープン
    errno_t result = fopen_s(&fp, "Resource/dat/ranking_data.txt", "r");

    // エラーチェック
    if (result != 0)
    {
        throw("Resource/dat/ranking_data.txtが開けませんでした\n");
    }

    // 対象ファイルから読み込む
    for (int i = 0; i < RANKING_DATA; i++)
    {
        fscanf_s(fp, "%d %d", &rank[i], &score[i]);
    }

    // ファイルクローズ
    fclose(fp);

}

// 更新処理
eSceneType RankingScene::Update()
{
    InputManager* input = InputManager::GetInstance();
    if (input->GetButtonDown(XINPUT_BUTTON_B))
    {
        PlaySoundMem(sound2[0], DX_PLAYTYPE_BACK, TRUE);
        
         return eSceneType::eTitle;
       
    }
	return GetNowSceneType();
}

// 描画処理
void RankingScene::Draw() const
{
	SetFontSize(20);
	DrawString(10, 10, "RANKING", 0xffffff);
    DrawString(10, 30, "A:Title", 0xffffff);

    SetFontSize(40);
	for (int i = 0; i < RANKING_DATA; ++i)
	{
        DrawFormatString(150, 100 + i * 60, GetColor(255, 255, 255), "No.%d  %d", i + 1, score[i]);
	}
}

// 終了時処理
void RankingScene::Finalize()
{

}

void RankingScene::SortData()
{
    for (int i = 0; i < RANKING_DATA - 1; i++)
    {
        for (int j = i + 1; j < RANKING_DATA; j++)
        {
            if (score[i] < score[j])
            {
                int tmp = score[i];
                score[i] = score[j];
                score[j] = tmp;
            }
        }
    }

    // 順位を整列させる
    for (int i = 0; i < RANKING_DATA; i++)
    {
        rank[i] = 1;
    }
    for (int i = 0; i < RANKING_DATA - 1; i++)
    {
        for (int j = i + 1; j < RANKING_DATA; j++)
        {
            if (score[i] > score[j])
            {
                rank[j]++;
            }
        }
    }
    // ランキングデータの書き込み
    FILE* fp = nullptr;

    // ファイルオープン
    errno_t result = fopen_s(&fp, "Resource/dat/ranking_data.txt", "w");

    // エラーチェック
    if (result != 0)
    {
        throw("Resource/dat/ranking_data.txtが開けませんでした\n");
    }

    // 対象ファイルに書き込み
    for (int i = 0; i < RANKING_DATA; i++)
    {
        fprintf(fp, "%d %d\n", rank[i], score[i]);
    }

    // ファイルクローズ
    fclose(fp);

}

void RankingScene::SetRank(int score)
{
    if (this->score[5] < score)
    {
        if (this->score[4] != score && this->score[3] != score && this->score[2] != score && this->score[1] != score && this->score[0] != score)
        {
            this->score[5] = score;
            SortData();
        }
        
    }
}

// 現在のシーン情報を返す
eSceneType RankingScene::GetNowSceneType() const
{
	return eSceneType::eRanking;
}
