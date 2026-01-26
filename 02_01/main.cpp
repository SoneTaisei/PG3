#include <stdio.h>
#include <Windows.h>

template <typename T>
T Min(T a, T b) {
	// aとbを比較し、aの方が小さければaを、そうでなければbを返す
	return (a < b) ? a : b;
}

int main() {
	// 文字コードをUTF-8にする
	SetConsoleOutputCP(65001);

	int iNum1 = 1;
	int iNum2 = 5;

	float fNum1 = 8.0f;
	float fNum2 = 7.5f;

	double dNum1 = 3.11;
	double dNum2 = 2.011;

	printf("int型の時 :: %d\n", Min<int>(iNum1, iNum2));
	printf("float型の時 :: %f\n", Min<float>(fNum1, fNum2));
	printf("double型の時 :: %lf\n", Min<double>(dNum1, dNum2));

	return 0;
}