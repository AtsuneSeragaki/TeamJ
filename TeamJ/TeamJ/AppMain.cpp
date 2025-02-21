#include "DxLib.h"
#include "Utility/InputManager.h"
#include "Utility/ResourceManager.h"
#include "Scene/SceneManager.h"

// 固定化するフレームレート値
#define TARGET_FREAM_RATE (60)
// 1フレーム当たりの時間(マイクロ秒)
#define DELTA_SECOND (1000000 / TARGET_FREAM_RATE)

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	// ウィンドウのタイトルを設定
	SetMainWindowText("TeamJ");

	//// ウィンドウサイズの設定
	//SetGraphMode(640, 480, 32);

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* manager = nullptr;
	int result = 0;

	try
	{
		manager = new SceneManager();

		manager->Initialize();

		InputManager* input = InputManager::GetInstance();

		// フレーム開始時間(マイクロ秒を取得)
		LONGLONG start_time = GetNowHiPerformanceCount();

		while (ProcessMessage() != -1 && manager->LoopCheck())
		{
			// 現在時間を取得
			LONGLONG now_time = GetNowHiPerformanceCount();

			// 1フレーム当たりの時間に到達したら、更新および描画処理を行う
			if ((now_time - start_time) >= DELTA_SECOND)
			{
				// フレーム開始時間を更新する
				start_time = now_time;

				input->Update();

				ClearDrawScreen();

				manager->Update();

				ScreenFlip();

				if (input->GetKeyInputState(KEY_INPUT_ESCAPE) == eInputState::eRelease)
				{
					break;
				}
			}
		}
	}
	catch (std::string& error_text)
	{
		OutputDebugString(error_text.c_str());
		result = -1;
	}

	InputManager::DeleteInstance();

	ResourceManager::DeleteInstance();

	if (manager != nullptr)
	{
		manager->Finalize();
		delete manager;
	}

	DxLib_End();

	return 0;
}