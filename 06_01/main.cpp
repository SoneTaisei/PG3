#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>

// 表示用の関数
void PrintThreadName (std::string name) {
	std::cout << name << std::endl;
}

int main () {
	SetConsoleOutputCP (65001);

	// thread 1 を作成し、終了を待つ
	std::thread th1 (PrintThreadName, "thread 1");
	th1.join (); // これにより thread 1 が終わるまで次へ進まない

	// thread 2 を作成し、終了を待つ
	std::thread th2 (PrintThreadName, "thread 2");
	th2.join ();

	// thread 3 を作成し、終了を待つ
	std::thread th3 (PrintThreadName, "thread 3");
	th3.join ();

	return 0;
}