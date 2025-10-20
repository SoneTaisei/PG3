#include <stdio.h>
#include <Windows.h>

int CalculateStandardPay(int timePay, int recorringPay, int workTime) {
	if(workTime <= 0) {
		return 0;
	} else {
		workTime--;
		return recorringPay + CalculateStandardPay(timePay, recorringPay * 2 - 50,workTime);
	}
}

int main() {
	SetConsoleOutputCP(65001);
	// 働く時間
	int workTime = 0;
	printf("何時間働きますか？↓\n");
	scanf_s("%d", &workTime);
	// 通常の金額
	int timePay = 1226;
	// 再帰した時の最初の金額
	int recorringPay = 100;
	printf("通常の金額 : %d\n", timePay * workTime);
	printf("再帰した時の金額 : %d\n", CalculateStandardPay(timePay, recorringPay, workTime));
	return 0;
}