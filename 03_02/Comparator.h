#pragma once
template <typename T1, typename T2>
class Comparator {
public:
	// 値を保存しておくための変数
	T1 val1;
	T2 val2;

	// コンストラクタ：渡された (10, 20) などを受け取って、変数に入れる
	Comparator (T1 a, T2 b) : val1 (a), val2 (b) {}
	auto Min () {
		return (val1 < val2) ? val1 : val2;
	}
};
