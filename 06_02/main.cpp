#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <Windows.h>

// 1. マップデータの型定義（2次元配列を想定）
using MapData = std::vector<std::vector<int>>;

// --- 共有資源 ---
std::queue<MapData> mapQueue;     // 読み込み済みデータの待機列
std::mutex mtx;                  // 共有資源を守る鍵
std::condition_variable cv;      // 準備完了を知らせるベル
bool isAppRunning = true;

// CSVファイルを自動生成する関数
void CreateDummyCSV (const std::string &filename) {
    std::ofstream ofs (filename);
    if (!ofs) return;

    // 5x5のサンプルマップデータ (0: 平地, 1: 壁, 2: ゴール)
    ofs << "1,1,1,1,1" << std::endl;
    ofs << "1,0,0,0,1" << std::endl;
    ofs << "1,0,1,0,1" << std::endl;
    ofs << "1,0,0,0,2" << std::endl;
    ofs << "1,1,1,1,1" << std::endl;

    ofs.close ();
    std::cout << "[System] " << filename << " has been created." << std::endl;
}

// 2. バックグラウンドでのCSV読み込み処理
void LoadCSVTask (const std::string &filename) {
    std::ifstream file (filename);
    MapData tempMap;
    std::string line;

    // ファイル読み込み（重い処理のシミュレート）
    if (file.is_open ()) {
        while (std::getline (file, line)) {
            std::vector<int> row;
            std::stringstream ss (line);
            std::string value;
            while (std::getline (ss, value, ',')) {
                row.push_back (std::stoi (value));
            }
            tempMap.push_back (row);
            // 読み込みの重さを出すために少し待機
            std::this_thread::sleep_for (std::chrono::milliseconds (100));
        }
    }

    // 読み終わったらキューへ（排他処理）
    {
        std::lock_guard<std::mutex> lock (mtx);
        mapQueue.push (tempMap);
    }
    cv.notify_all (); // メインスレッドに「準備できたよ！」と通知
}

int main () {
    SetConsoleOutputCP (65001);

    // マップチップのcsvを作成。
    CreateDummyCSV ("map_data.csv");

    std::cout << "--- Game Start! Loading Map in background ---" << std::endl;

    // 3. バックグラウンドスレッドの起動
    // ※本来は "map.csv" が必要ですが、ここでは処理の流れを示します
    std::thread loader (LoadCSVTask, "map_data.csv");

    // 4. メインループ（ゲームループ）
    while (isAppRunning) {
        // ゲームの他の更新や描画をここで行う（フリーズしない！）
        static int frameCount = 0;
        std::cout << "\rProcessing frame: " << ++frameCount << std::flush;

        // データのチェック（非ブロッキングで行うのが一般的）
        MapData currentMap;
        bool hasLoaded = false;

        {
            std::lock_guard<std::mutex> lock (mtx);
            if (!mapQueue.empty ()) {
                currentMap = mapQueue.front ();
                mapQueue.pop ();
                hasLoaded = true;
            }
        }

        // 読み込みが完了していたら表示
        if (hasLoaded) {
            std::cout << "\n\n[Map Loaded!] Displaying Chips:" << std::endl;
            for (const auto &row : currentMap) {
                for (int chip : row) {
                    std::cout << "[" << chip << "]"; // マップチップの表示
                }
                std::cout << std::endl;
            }
            isAppRunning = false; // 表示したら終了
        }

        std::this_thread::sleep_for (std::chrono::milliseconds (16)); // 約60fps
    }

    // 5. アプリ終了時にスレッドを回収
    if (loader.joinable ()) {
        loader.join ();
    }

    std::cout << "Program finished safely." << std::endl;
    return 0;
}