#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>
#include <atomic>
#include <cstdio>

const int mapxMax = 70;
const int mapyMax = 30;
int map[mapyMax][mapxMax];

int main() {
    std::mutex mutex;
    std::condition_variable condition;
    std::queue<int> q;
    std::atomic<bool> exit(false);

    // バックグラウンドスレッド
    std::thread th([&]() {
        while (!exit) {
            std::this_thread::sleep_for(std::chrono::microseconds(4000));

            // ファイル読み込み
            FILE* fp = nullptr;
            if (fopen_s(&fp, "mapSampleGame.csv", "rt") != 0) {
                std::cerr << "Failed to open file.\n";
                return;
            }

            int numRects = 0;
            while (numRects < mapxMax * mapyMax && fscanf_s(fp, "%d,", &map[numRects / mapxMax][numRects % mapxMax]) != EOF) {
                ++numRects;
            }
            fclose(fp);

            // ファイル読み込み後、メインスレッドに通知
            condition.notify_all();
        }
        });

    // メインスレッドでキューにデータをプッシュ
    for (int i = 0; i < 1; ++i) {
        std::lock_guard<std::mutex> lock(mutex);
        q.push(i);  // キューにデータをプッシュ
        condition.notify_one(); // 通知を送る
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // メインスレッドでキューを表示
    while (!q.empty()) {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Queue data: " << q.front() << std::endl;
        q.pop();
    }

    // マップの表示（読み込んだデータを表示）
    std::cout << "\nMap data:\n";
    for (int y = 0; y < mapyMax; ++y) {
        for (int x = 0; x < mapxMax; ++x) {
            std::cout << map[y][x] << " ";
        }
        std::cout << "\n";
    }

    exit = true;
    condition.notify_all();

    th.join(); // スレッド終了を待つ

    return 0;
}
