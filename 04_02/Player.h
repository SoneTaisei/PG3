#pragma once
#include "Vector2.h"
class Player {
private:
	Vector2 pos_;
	Vector2 width_;
public:
	Player ();
	void Init ();
	void Update ();
	void Draw ();

	// メンバ変数
	void MoveRight ();
	void MoveLeft ();
};

