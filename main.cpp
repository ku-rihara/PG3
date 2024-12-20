#include <stdio.h>
#include <thread>
#include <array>
#include <string>
#include <mutex>


std::mutex mtx;
std::condition_variable cv;
int currentId = 0;

// 文字出力する関数
void threadMessage(const std::string& message, int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [id] { return id == currentId; });

    printf("%s\n", message.c_str());

    ++currentId;
    cv.notify_all();
}

int main() {
    std::array<std::thread, 3> th;

    // 並行処理
    for (uint32_t i = 0; i < th.size(); ++i) {
        th[i] = std::thread(threadMessage, "thread" + std::to_string(i + 1), i);
    }

    // スレッドの完了を待機
    for (uint32_t i = 0; i < th.size(); ++i) {
        th[i].join();
    }

    return 0;
}
