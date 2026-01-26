#pragma once
#include "IScene.h"

// ゲームオブジェクト用のシンプルな構造体
struct Vector2 {
	float x, y;
};

struct Player {
	Vector2 pos;
	float radius;
	float speed;
};

struct Bullet {
	Vector2 pos;
	float radius;
	float speed;
	bool isAlive;
};

struct Enemy {
	Vector2 pos;
	float radius;
	float speed;
	bool isAlive;
};

class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Player player_;
	Bullet bullet_;
	Enemy enemy_;
};