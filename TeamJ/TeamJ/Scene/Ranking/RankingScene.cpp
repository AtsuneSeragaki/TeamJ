#include "RankingScene.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"

// コンストラクタ
RankingScene::RankingScene() :score{}, rank{}, sound2{},button_image(), font_button(), font_scene_name(), font_score(),ranking_bgm()
{
}

// デストラクタ
RankingScene::~RankingScene()
{
}

// 初期化処理
void RankingScene::Initialize()
{
    //画像のの読み込み
    ResourceManager* rm = ResourceManager::GetInstance();
    std::vector<int>tmp;
    tmp = rm->GetImages("Resource/Images/ranking.png");
    background_image = tmp[0];
    tmp = rm->GetImages("Resource/Images/buttonLong_brown.png");
    button_image = tmp[0];
    tmp = rm->GetImages("Resource/Images/buttonLong_beige.png");
    button_image = tmp[0];
    //音源の読込み
    int tmp2;
    tmp2 = rm->GetSounds("Resource/Sounds/gun_shot.mp3");
    sound2[0] = tmp2;
    tmp2 = rm->GetSounds("Resource/Sounds/cursor_sound.mp3");
    sound2[1] = tmp2;
    
    //BGMの読み込み
    int tmp3;
    tmp3 = rm->GetSounds("Resource/Sounds/Bruyeres_2.mp3");
    ranking_bgm= tmp3;

    //フォントの読み込み
    font_scene_name = CreateFontToHandle("Stencil", 65, -1, DX_FONTTYPE_ANTIALIASING_4X4);
    font_button = CreateFontToHandle("Stencil", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4);
    font_score = CreateFontToHandle("Stencil", 85, -1, DX_FONTTYPE_ANTIALIASING_4X4);
	
    //
    bgm_flg = false;

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
    //一度だけこの処理を通るようにする
    if (bgm_flg == false)
    {
        //BGMの再生を最初から流れるよう設定
        SetSoundCurrentTime(0, ranking_bgm);
        //BGMのの再生
        PlaySoundMem(ranking_bgm, DX_PLAYTYPE_BACK, FALSE);

        //trueにし、何度も更新しないようにする
        bgm_flg = true;
    }
    

    //Bボタンを押したらタイトルに戻るようにする
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
    //背景画像の描画
    DrawExtendGraph(-25, -50, 665, 530, background_image, FALSE);

    //真ん中にRANKINGの文字を描画
    DrawStringToHandle(180, 20, "RANKING", 0x000000, font_scene_name);

    //順位の描画
    for (int i = 0; i < RANKING_DATA - 2; ++i)
	{
        DrawFormatStringToHandle(80, 105 + i * 85, GetColor(0, 0, 0), font_score, "No.%d  %05d", i + 1, score[i]);
	}

    //タイトルに戻るボタンの描画
    DrawRotaGraphF(330, 410, 1.0f, 0.0f, button_image, TRUE, FALSE);
    DrawStringToHandle(275, 385, "TITLE", 0x000000, font_button);
}

// 終了時処理
void RankingScene::Finalize()
{
    //BGMの再生を止める
    StopSoundMem(ranking_bgm);

    //フラグのリセット
    bgm_flg = false;
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
    //5位から順位を設定する
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
