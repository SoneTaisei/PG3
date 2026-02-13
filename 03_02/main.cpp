#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "Comparator.h"

int main () {
	SetConsoleOutputCP (65001);
	// --- 同じ型同士 ---

	// 1. int と int → 答えは int なので %d
	Comparator<int, int> c1 (10, 20);
	printf ("1. int-int: %d\n", c1.Min ());

	// 2. float と float → 答えは float なので %f
	Comparator<float, float> c2 (3.5f, 2.1f);
	printf ("2. float-float: %f\n", c2.Min ());

	// 3. double と double → 答えは double なので %f (または %lf)
	Comparator<double, double> c3 (5.55, 9.99);
	printf ("3. double-double: %f\n", c3.Min ());


	// --- 違う型同士 (ここが要注意！) ---
	// 違う型同士だと、基本的には「小数」の方に合わせて返ってきます

	// 4. int と float → 答えは float になるので %f
	Comparator<int, float> c4 (5, 4.2f);
	printf ("4. int-float: %f\n", c4.Min ());

	// 5. int と double → 答えは double になるので %f
	Comparator<int, double> c5 (10, 3.14);
	printf ("5. int-double: %f\n", c5.Min ());

	// 6. float と double → 答えは double になるので %f
	Comparator<float, double> c6 (2.5f, 2.49);
	printf ("6. float-double: %f\n", c6.Min ());

	return 0;
}