#include <Novice.h>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "InputManager.h"

const char kWindowTitle[] = "LE2B_13_ソネ_タイセイ - State Pattern";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// シーン管理用のポインタと、現在のシーン番号を保持する変数
	IScene* currentScene = new TitleScene();
	currentScene->Init();
	Scene sceneNo = Scene::TITLE;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を更新
		InputManager::GetInstance()->Update();

		///
		/// ↓更新処理ここから
		///

		// 現在のシーンの更新処理を呼び出す
		currentScene->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 現在のシーンの描画処理を呼び出す
		currentScene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// シーン切り替え処理
		if (sceneNo != currentScene->GetNextScene()) {
			sceneNo = currentScene->GetNextScene();
			delete currentScene;

			switch (sceneNo) {
			case Scene::TITLE:
				currentScene = new TitleScene();
				break;
			case Scene::STAGE:
				currentScene = new StageScene();
				break;
			case Scene::CLEAR:
				currentScene = new ClearScene();
				break;
			}
			currentScene->Init();
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::GetInstance()->IsKeyTriggered(DIK_ESCAPE)) {
			break;
		}
	}

	// 最後のシーンのメモリを解放
	delete currentScene;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
