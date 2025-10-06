#include <stdio.h>
#include <Windows.h>
#include <algorithm>
#include <iostream> 
#include <vector>
#include <string>

int main() {
	// 文字コードをUTF-8にする
	SetConsoleOutputCP(65001);

	// 配列を作る
	std::vector<std::string> nameList = {
		"k024g1017@g.neec.ac.jp","k024g0033@g.neec.ac.jp","k024g0057@g.neec.ac.jp","k024g0020@g.neec.ac.jp",
		"k024g0109@g.neec.ac.jp","k024g1031@g.neec.ac.jp","k024g0004@g.neec.ac.jp","k024g0027@g.neec.ac.jp",
		"k024g0058@g.neec.ac.jp","k022g0113@g.neec.ac.jp","k024g0007@g.neec.ac.jp","k024g0083@g.neec.ac.jp",
		"k024g0110@g.neec.ac.jp","k024g0066@g.neec.ac.jp","k023g0029@g.neec.ac.jp","k024g1030@g.neec.ac.jp",
		"k024g0106@g.neec.ac.jp","k024g0089@g.neec.ac.jp","k024g0101@g.neec.ac.jp","k024g0035@g.neec.ac.jp",
		"k024g1025@g.neec.ac.jp","k024g0059@g.neec.ac.jp","k024g0006@g.neec.ac.jp","k023g0122@g.neec.ac.jp",
		"k024g0028@g.neec.ac.jp","k024g1024@g.neec.ac.jp","k024g0108@g.neec.ac.jp","k024g0061@g.neec.ac.jp",
		"k024g0104@g.neec.ac.jp","k024g0038@g.neec.ac.jp","k024g0032@g.neec.ac.jp","k024g0026@g.neec.ac.jp",
		"k024g0001@g.neec.ac.jp","k024g0009@g.neec.ac.jp","k024g0112@g.neec.ac.jp","k024g0011@g.neec.ac.jp",
		"k024g0085@g.neec.ac.jp","k024g0111@g.neec.ac.jp","k024g0045@g.neec.ac.jp","k024g0103@g.neec.ac.jp",
		"k024g1002@g.neec.ac.jp","k024g0078@g.neec.ac.jp","k024g0044@g.neec.ac.jp","k024g0008@g.neec.ac.jp",
		"k024g0075@g.neec.ac.jp","k024g0091@g.neec.ac.jp","k024g0064@g.neec.ac.jp","k024g0051@g.neec.ac.jp",
		"k024g0093@g.neec.ac.jp","k024g0024@g.neec.ac.jp",
	};

	std::sort(nameList.begin(), nameList.end(), [](const std::string &a, const std::string &b) {
		// 文字列aから学籍番号の部分を抜き出す
		size_t g_pos = a.find('g');       // 'g'の位置を探す
		size_t at_pos = a.find('@');      // '@'の位置を探す
		// 'g'の次の文字から、'@'の手前までの部分を切り出す
		std::string id_str_a = a.substr(g_pos + 1, at_pos - (g_pos + 1));
		int id_a = std::stoi(id_str_a);     // 文字列を整数に変換


		std::string id_str_b = b.substr(g_pos + 1, at_pos - (g_pos + 1));
		int id_b = std::stoi(id_str_b);

		// 整数に変換した学籍番号を比較する
		if(id_a < id_b) {
			// aの学籍番号がbより小さいので、aを先に並べる -> trueを返す
			return true;
		} else {
			// aの学籍番号がb以上なので、aを先に並べる必要はない -> falseを返す
			return false;
		}
			  });


	// ステップ4: 結果の表示
	std::cout << "--- 学籍番号順に表示する ---" << std::endl;
	for(const std::string &newNameList : nameList) {
		std::cout << newNameList << std::endl;
	}

	return 0;
}