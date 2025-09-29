#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 駅一覧をきれいに表示するための関数
void print_stations(int year, const list<const char *> &stations) {
    cout << "----------------------------------------" << endl;
    cout << "Yamanote Line Stations in " << year << endl;
    cout << "----------------------------------------" << endl;
    for(const char *station : stations) {
        cout << "- " << station << endl;
    }
    cout << endl;
}

int main() {
    // ----------------------------------------
    // 1. 1970年時点の山手線リストを作成
    // 西日暮里駅(1971年開業)と高輪ゲートウェイ駅(2020年開業)はまだ存在しない。
    // ----------------------------------------
    list<const char *> yamanote_1970 = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
        "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi",
        "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki",
        "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    // 1970年時点の駅一覧を表示
    print_stations(1970, yamanote_1970);


    // ----------------------------------------
    // 2. 2019年時点の山手線リストを作成
    // 西日暮里駅が追加されている。
    // ----------------------------------------
    list<const char *> yamanote_2019 = yamanote_1970; // 1970年のリストをコピー

    // 「田端駅」を探し、その手前に「西日暮里駅」を挿入する
    auto it_tabata = find(yamanote_2019.begin(), yamanote_2019.end(), "Tabata");
    if(it_tabata != yamanote_2019.end()) {
        yamanote_2019.insert(it_tabata, "Nishi-Nippori");
    }

    // 2019年時点の駅一覧を表示
    print_stations(2019, yamanote_2019);


    // ----------------------------------------
    // 3. 2022年時点の山手線リストを作成
    // 高輪ゲートウェイ駅が追加されている。
    // ----------------------------------------
    list<const char *> yamanote_2022 = yamanote_2019; // 2019年のリストをコピー

    // 「田町駅」を探し、その手前に「高輪ゲートウェイ駅」を挿入する
    auto it_tamachi = find(yamanote_2022.begin(), yamanote_2022.end(), "Tamachi");
    if(it_tamachi != yamanote_2022.end()) {
        yamanote_2022.insert(it_tamachi, "Takanawa Gateway");
    }

    // 2022年時点の駅一覧を表示
    print_stations(2022, yamanote_2022);

    return 0;
}