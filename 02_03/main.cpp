#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

void ShowResult(int roll, int userGuess) {
	printf("出目は %d でした。\n", roll);

	// 判定ロジック
	// (出目が奇数 かつ ユーザーの予想が1) または (出目が偶数 かつ ユーザーの予想が0) なら正解
	if((roll % 2 != 0 && userGuess == 1) || (roll % 2 == 0 && userGuess == 0)) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

void DelayReveal(void (*fn)(int, int), unsigned int dlayMs, int roll, int userGuess) {
	// 入力中というテキストを出す
	printf("入力中...");

	// 数秒待ってからはじめる
	Sleep(dlayMs);

	// ShowResultの関数ポインタを使う
	fn(roll,userGuess);
}

int main() {
	SetConsoleOutputCP(65001);
	srand((unsigned int)time(NULL));

	// 1. さいころの出目をランダムで出す
	int diceRoll = rand() % 6 + 1;

	// 2. ユーザーから予想を入力してもらう
	int userGuess = 0;
	printf("サイコロの目は奇数(1)？ 偶数(0)？↓\n");
	scanf_s("%d", &userGuess);

	// 3. DelayRevealを呼び出す (3秒後にShowResultを呼び出すよう指示)
	DelayReveal(ShowResult, 3000, diceRoll, userGuess);
	


	return 0;
}