#include <stdio.h>
#include <Windows.h>

// 再帰的な賃金計算（n時間目の単価ではなく、累計を出す）
int CalculateTotalRecursivePay (int currentPay, int remainingHours) {
    if (remainingHours <= 1) {
        return currentPay;
    }
    // 次の1時間からは「前の1時間 * 2 - 50」
    int nextPay = currentPay * 2 - 50;
    return currentPay + CalculateTotalRecursivePay (nextPay, remainingHours - 1);
}

int main () {
    SetConsoleOutputCP (65001);

    int normalHourlyWage = 1226;
    int initialRecursiveWage = 100;
    int inputHours = 0;

    printf ("シミュレーションする時間を入力してください: ");
    scanf_s ("%d", &inputHours);

    printf ("\n時間 | 一般賃金累計 | 再帰賃金累計 | 判定\n");
    printf ("------------------------------------------\n");

    for (int i = 1; i <= inputHours; i++) {
        int normalTotal = normalHourlyWage * i;
        int recursiveTotal = CalculateTotalRecursivePay (initialRecursiveWage, i);

        const char *result = (recursiveTotal > normalTotal) ? "★再帰の勝ち" : "一般の勝ち";

        printf ("%2dh  | %10d円 | %10d円 | %s\n", i, normalTotal, recursiveTotal, result);
    }

    return 0;
}