#include <stdio.h>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(65001);
	char std[] = "あ";
	printf("%s",std);
	return 0;
}