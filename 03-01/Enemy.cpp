#include "Enemy.h"
#include <stdio.h>

void Enemy::Initialize() {
	pState = &Enemy::Approach;
}

void Enemy::Update() {
	if(pState != nullptr) {
		(this->*pState)();
	}
}

void Enemy::Approach() {
	printf("敵が接近しました\n");

	// 次の状態へ遷移（ポインタの中身を書き換え）
	pState = &Enemy::Shoot;
}

void Enemy::Shoot() {
	printf("敵が射撃しました\n");

	// 次の状態へ遷移
	pState = &Enemy::Retreat;
}

void Enemy::Retreat() {
	printf("敵が離脱しました\n");

	// 離脱後は何もしないならnullptrにするか、
	// 最初に戻るなら &Enemy::Approach にする
	pState = nullptr;
}

