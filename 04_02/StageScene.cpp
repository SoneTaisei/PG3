#include "StageScene.h"
#include "InputManager.h"
#include <Novice.h>
#include <cmath> // sqrt用

// 2点間の距離を計算するヘルパー関数
float GetDistance (const Vector2 &p1, const Vector2 &p2) {
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	return std::sqrt (dx * dx + dy * dy);
}

void StageScene::Init () {
	inputhandler_ = new InputHandler ();

	inputhandler_->AssignMoveRightCommand2PressKeyD ();
	inputhandler_->AssignMoveLeftCommand2PressKeyA ();

	player_ = new Player ();
}

void StageScene::Update () {
	iCommand_ = inputhandler_->HandleInput ();

	if (this->iCommand_) {
		iCommand_->Exec (*player_);
	}

	player_->Update ();
}

void StageScene::Draw () {
	// プレイヤーの描画
	Novice::DrawEllipse (
		static_cast<int>(player_.pos.x), static_cast<int>(player_.pos.y),
		static_cast<int>(player_.radius), static_cast<int>(player_.radius), 0.0f, WHITE, kFillModeSolid);

	// 弾の描画
	if (bullet_.isAlive) {
		Novice::DrawEllipse (
			static_cast<int>(bullet_.pos.x), static_cast<int>(bullet_.pos.y),
			static_cast<int>(bullet_.radius), static_cast<int>(bullet_.radius), 0.0f, RED,
			kFillModeSolid);
	}

	// 敵の描画
	if (enemy_.isAlive) {
		Novice::DrawEllipse (
			static_cast<int>(enemy_.pos.x), static_cast<int>(enemy_.pos.y),
			static_cast<int>(enemy_.radius), static_cast<int>(enemy_.radius), 0.0f, BLUE,
			kFillModeSolid);
	}

	Novice::ScreenPrintf (10, 10, "STAGE SCENE");
}