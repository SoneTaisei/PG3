#include <iostream>
#include <vector>
#include <string>
#include <windows.h> // SetConsoleOutputCPを使うために必要

// 【条件1】現実世界（ゲーム会社）の関係をクラスで実装
// 基底クラス：ゲーム会社
class GameCompany {
protected:
	std::string companyName;

public:
	GameCompany (std::string name) : companyName (name) {}

	// 仮想関数：開発する
	// 「ゲームを作る」という命令は同じでも、会社によって作るものが違う
	virtual void Develop () const = 0;

	// 会社名を表示
	void ShowName () const {
		std::cout << "【内定先: " << companyName << "】" << std::endl;
	}

	virtual ~GameCompany () {}
};

// 派生クラス：任天堂
class Nintendo : public GameCompany {
public:
	Nintendo () : GameCompany ("任天堂") {}

	void Develop () const override {
		std::cout << "　業務：マリオやゼルダなどの、誰もが楽しめるゲームを作ります。" << std::endl;
	}
};

// 派生クラス：セガ
class Sega : public GameCompany {
public:
	Sega () : GameCompany ("セガ") {}

	void Develop () const override {
		std::cout << "　業務：ソニックや龍が如くなど、エッジの効いたゲームを作ります。" << std::endl;
	}
};

// 派生クラス：カプコン
class Capcom : public GameCompany {
public:
	Capcom () : GameCompany ("カプコン") {}

	void Develop () const override {
		std::cout << "　業務：モンスターハンターやバイオハザードなど、世界的アクションゲームを作ります。" << std::endl;
	}
};

// 追加の派生クラス：スクウェア・エニックス
class SquareEnix : public GameCompany {
public:
	SquareEnix () : GameCompany ("スクウェア・エニックス") {}

	void Develop () const override {
		std::cout << "　業務：ファイナルファンタジーやドラゴンクエストなど、壮大なRPGを作ります。" << std::endl;
	}
};

int main () {
	// コンソールの文字コードをUTF-8に設定（文字化け防止）
	SetConsoleOutputCP (65001);

	// 【条件2】インスタンスを生成
	Nintendo nintendo;
	Sega sega;
	Capcom capcom;
	SquareEnix sqex;

	// ポリモーフィズム：これら全ての会社を「ゲーム会社」という一つの型で扱える
	std::vector<GameCompany *> myCareerPath = { &nintendo, &sega, &capcom, &sqex };

	std::cout << "--- ゲーム業界就職シミュレーション ---" << std::endl;

	for (GameCompany *company : myCareerPath) {
		company->ShowName ();

		// ポリモーフィズム実行
		company->Develop ();

		std::cout << "--------------------------------------" << std::endl;
	}

	return 0;
}