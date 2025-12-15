#include <iostream>

// ---------------------------------------------------------
// 1. 抽象クラス IShape
// ---------------------------------------------------------
class IShape {
public:
    // 純粋仮想関数（継承先で必ず中身を作る必要がある）
    virtual void Size () = 0;
    virtual void Draw () = 0;

    // 仮想デストラクタ
    virtual ~IShape () {}
};

// ---------------------------------------------------------
// 2. Circle クラス (IShapeを継承)
// ---------------------------------------------------------
class Circle : public IShape {
private:
    float radius; // 半径
    float area;   // 面積

public:
    // コンストラクタ：半径をセット
    Circle (float r) : radius (r), area (0.0f) {}

    // 面積を計算 (半径 × 半径 × 3.14)
    void Size () override {
        area = radius * radius * 3.14f;
    }

    // 値を表示
    void Draw () override {
        std::cout << "Circle (半径" << radius << ") の面積: " << area << std::endl;
    }
};

// ---------------------------------------------------------
// 3. Rectangle クラス (IShapeを継承)
// ---------------------------------------------------------
class Rectangle : public IShape {
private:
    float width;  // 幅
    float height; // 高さ
    float area;   // 面積

public:
    // コンストラクタ：幅と高さをセット
    Rectangle (float w, float h) : width (w), height (h), area (0.0f) {}

    // 面積を計算 (幅 × 高さ)
    void Size () override {
        area = width * height;
    }

    // 値を表示
    void Draw () override {
        std::cout << "Rectangle (幅" << width << ", 高さ" << height << ") の面積: " << area << std::endl;
    }
};

// ---------------------------------------------------------
// メイン関数 (コンソールアプリとしての実行部分)
// ---------------------------------------------------------
int main () {
    // Circle（円）の作成と実行
    Circle circle (10.0f); // 半径10
    circle.Size ();        // 計算
    circle.Draw ();        // 表示

    // Rectangle（矩形）の作成と実行
    Rectangle rect (5.0f, 8.0f); // 幅5, 高さ8
    rect.Size ();                // 計算
    rect.Draw ();                // 表示

    return 0;
}