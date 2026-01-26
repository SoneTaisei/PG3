#include "StageScene.h"
#include "InputManager.h"
#include <Novice.h>
#include <cmath> // sqrt用

// 2点間の距離を計算するヘルパー関数
float GetDistance(const Vector2& p1, const Vector2& p2) {
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	return std::sqrt(dx * dx + dy * dy);
}

void StageScene::Init() {
	nextScene_ = Scene::STAGE;

	// 各オブジェクトの初期化
	player_ = {{640.0f, 650.0f}, 20.0f, 5.0f};
	bullet_ = {{0.0f, 0.0f}, 10.0f, 10.0f, false};
	enemy_ = {{640.0f, 100.0f}, 30.0f, 3.0f, true};
}

void StageScene::Update() {
	InputManager* input = InputManager::GetInstance();

	// プレイヤーの移動
	if (input->IsKeyPressed(DIK_A) && player_.pos.x > player_.radius) {
		player_.pos.x -= player_.speed;
	}
	if (input->IsKeyPressed(DIK_D) && player_.pos.x < 1280.0f - player_.radius) {
		player_.pos.x += player_.speed;
	}

	// 弾の発射
	if (input->IsKeyTriggered(DIK_SPACE) && !bullet_.isAlive) {
		bullet_.isAlive = true;
		bullet_.pos = player_.pos;
	}

	// 弾の更新
	if (bullet_.isAlive) {
		bullet_.pos.y -= bullet_.speed;
		// 画面外に出たら弾を消す
		if (bullet_.pos.y < -bullet_.radius) {
			bullet_.isAlive = false;
		}
	}

	// 敵の更新（左右に往復）
	if (enemy_.isAlive) {
		enemy_.pos.x += enemy_.speed;
		if (enemy_.pos.x < enemy_.radius || enemy_.pos.x > 1280.0f - enemy_.radius) {
			enemy_.speed *= -1.0f;
		}
	}

	// 当たり判定: 弾と敵
	if (bullet_.isAlive && enemy_.isAlive) {
		float distance = GetDistance(bullet_.pos, enemy_.pos);
		if (distance < bullet_.radius + enemy_.radius) {
			bullet_.isAlive = false;
			enemy_.isAlive = false;
		}
	}

	// 勝利条件: 敵を倒したらクリアシーンへ
	if (!enemy_.isAlive) {
		nextScene_ = Scene::CLEAR;
	}
}

void StageScene::Draw() {
	// プレイヤーの描画
	Novice::DrawEllipse(
	    static_cast<int>(player_.pos.x), static_cast<int>(player_.pos.y),
	    static_cast<int>(player_.radius), static_cast<int>(player_.radius), 0.0f, WHITE, kFillModeSolid);

	// 弾の描画
	if (bullet_.isAlive) {
		Novice::DrawEllipse(
		    static_cast<int>(bullet_.pos.x), static_cast<int>(bullet_.pos.y),
		    static_cast<int>(bullet_.radius), static_cast<int>(bullet_.radius), 0.0f, RED,
		    kFillModeSolid);
	}

	// 敵の描画
	if (enemy_.isAlive) {
		Novice::DrawEllipse(
		    static_cast<int>(enemy_.pos.x), static_cast<int>(enemy_.pos.y),
		    static_cast<int>(enemy_.radius), static_cast<int>(enemy_.radius), 0.0f, BLUE,
		    kFillModeSolid);
	}

	Novice::ScreenPrintf(10, 10, "STAGE SCENE");
}