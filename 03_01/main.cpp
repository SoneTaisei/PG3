#include <stdio.h>
#include <Windows.h>
#include"Enemy.h"

int main() {
	SetConsoleOutputCP(65001);
	// 敵の生成
	Enemy enemy;

	enemy.Initialize();

	for(int i = 0; i < 3; ++i) {
		enemy.Update();
	}

	return 0;
}