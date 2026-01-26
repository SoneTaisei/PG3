#include "TitleScene.h"
#include "InputManager.h"
#include <Novice.h>

// ISceneの静的メンバ変数をここで実体化（一度だけ行う）
Scene IScene::nextScene_ = Scene::TITLE;

void TitleScene::Init() {
	// 初期化時に次のシーンを自分自身に設定し、即時遷移を防ぐ
	nextScene_ = Scene::TITLE;
}

void TitleScene::Update() {
	// Enterキーが押されたら、次のシーンをSTAGEに設定
	if (InputManager::GetInstance()->IsKeyTriggered(DIK_RETURN)) {
		nextScene_ = Scene::STAGE;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(600, 360, "TITLE SCENE");
	Novice::ScreenPrintf(550, 400, "PRESS ENTER TO START");
}