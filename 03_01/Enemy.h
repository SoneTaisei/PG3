#pragma once
class Enemy {
public:

	void Initialize ();
	void Update ();
private:
	// メンバ関数ポインタ
	void(Enemy:: *pState)();

	// 行動パターン
	void Approach ();
	void Shoot ();
	void Retreat ();
};

