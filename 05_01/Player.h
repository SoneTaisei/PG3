#pragma once
#include "Vector2.h"
class Player {
private:
	Vector2 pos_;
	float speed_;
public:
	Player ();

	void Input ();
	void Update ();
	void Draw ();

	// メンバ変数
	void MoveRight ();
	void MoveLeft ();

};

