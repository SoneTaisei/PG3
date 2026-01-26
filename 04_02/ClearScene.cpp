#include "ClearScene.h"
#include "InputManager.h"
#include <Novice.h>

void ClearScene::Init() {
	nextScene_ = Scene::CLEAR;
}

void ClearScene::Update() {
	if (InputManager::GetInstance()->IsKeyTriggered(DIK_RETURN)) {
		nextScene_ = Scene::TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(600, 360, "GAME CLEAR!");
	Novice::ScreenPrintf(520, 400, "PRESS ENTER TO RETURN TO TITLE");
}