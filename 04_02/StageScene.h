#pragma once
#include "IScene.h"
#include "Command.h"
#include "InputHandler.h"
#include "Player.h"

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
	void Init () override;
	void Update () override;
	void Draw () override;

	StageScene ();
	void Init ()override;
	void Update ()override;
	void Draw () override;

private:
	InputHandler *inputhandler_ = nullptr;
	ICommand *iCommand_ = nullptr;
	Player *player_;
	Bullet bullet_;
	Enemy enemy_;
};