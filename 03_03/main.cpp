#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <memory>  // std::unique_ptr を使うための必須ヘッダー
#include <Windows.h>

namespace Geometry {

	// --- 【設計図：抽象クラス】 ---
	// 全ての図形が守るべき「規約（インターフェース）」を定義します
	class IShape {
	public:
		// 「面積を返すこと」という命令。= 0 は「実装は子クラスに任せる」という意味
		virtual double Size () const = 0;
		// 「情報を表示すること」という命令
		virtual void Draw () const = 0;
		// 賢いポインタを使うために、デストラクタも仮想化して安全に消せるようにする
		virtual ~IShape () {}
	};

	// --- 【実装：円クラス】 ---
	class Circle : public IShape {
	private:
		double radius;
	public:
		Circle (double r) : radius (r) {}

		// 円のルールに沿って面積を計算
		double Size () const override {
			return 3.141592653589793 * radius * radius;
		}

		void Draw () const override {
			std::cout << "図形: 円 / 半径: " << radius << std::endl;
		}
	};

	// --- 【実装：長方形クラス】 ---
	class Rectangle : public IShape {
	private:
		double width, height;
	public:
		Rectangle (double w, double h) : width (w), height (h) {}

		// 長方形のルールに沿って面積を計算
		double Size () const override {
			return width * height;
		}

		void Draw () const override {
			std::cout << "図形: 長方形 / 幅: " << width << ", 高さ: " << height << std::endl;
		}
	};

} // namespace Geometry

int main () {
	// コンソールの文字化け対策（UTF-8設定）
	SetConsoleOutputCP (65001);

	// --- 【管理：スマートポインタの動的配列】 ---
	// Geometry::IShape を指す「賢いポインタ」を格納する箱（vector）を用意
	// これにより、Circle も Rectangle も混ぜて管理できる（これがポリモーフィズム！）
	std::vector<std::unique_ptr<Geometry::IShape>> shapes;

	// インスタンスを生成してリストに追加
	// std::make_unique を使うことで、安全にメモリを確保します
	shapes.push_back (std::make_unique<Geometry::Circle> (5.0));
	shapes.push_back (std::make_unique<Geometry::Rectangle> (4.0, 6.0));

	std::cout << "--- 図形計算システム (Smart Pointer版) ---" << std::endl;

	// --- 【実行：多態性の活用】 ---
	// shape が実際には「円」なのか「長方形」なのかを意識せず、
	// ただ「図形」として Size() や Draw() を呼び出せば、適切な方が実行されます
	for (const auto &shape : shapes) {
		shape->Draw ();
		std::cout << "面積: " << shape->Size () << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	// 最後に delete ループを書く必要はありません。
	// main関数が終わると shapes が消え、中身の unique_ptr たちが勝手にメモリを掃除してくれます。
	return 0;
}