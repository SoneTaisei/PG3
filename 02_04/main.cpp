#include <cstdio>      // printf, scanf_s のため (C++風)
#include <cstdlib>     // srand, rand のため (C++風)
#include <ctime>       // time のため (C++風)
#include <Windows.h>   // Sleep, SetConsoleOutputCP のため
#include <functional>  // std::function のため (C++で必須)

// std::function を使うように引数を変更
// 「引数がなく、戻り値もない関数」を受け取るようにする
void DelayReveal(std::function<void(void)> fn, unsigned int dlayMs) {
	// 入力中というテキストを出す
	printf("入力中...");

	// 数秒待ってからはじめる
	Sleep(dlayMs);

	// 受け取った関数(ラムダ式)を実行する
	fn();
}

// ShowResult関数は不要になるので削除します。

int main() {
	SetConsoleOutputCP(65001);
	srand((unsigned int)time(NULL));

	// 1. さいころの出目をランダムで出す
	int diceRoll = rand() % 6 + 1;

	// 2. ユーザーから予想を入力してもらう
	int userGuess = 0;
	printf("サイコロの目は奇数(1)？ 偶数(0)？↓\n");
	scanf_s("%d", &userGuess);

	// 3. DelayRevealを呼び出す
	// ここでラムダ式を直接定義して渡す
	DelayReveal(
		// [=] は、外側にある変数(diceRoll, userGuess)を
		// コピーしてラムダ式の中で使えるようにする「キャプチャ」
		[=]() {
			// --- ここから下が元の ShowResult の処理 ---
			printf("出目は %d でした。\n", diceRoll);

			// 判定ロジック
			if((diceRoll % 2 != 0 && userGuess == 1) || (diceRoll % 2 == 0 && userGuess == 0)) {
				printf("正解\n");
			} else {
				printf("不正解\n");
			}
			// --- ここまでが元の ShowResult の処理 ---
		},
		3000 // 待機時間
	);

	return 0;
}