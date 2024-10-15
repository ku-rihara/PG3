#include <stdio.h>
//std
#include<functional>
#include<random>
#include<thread>

std::random_device rd;
std::mt19937 random(rd());
//1から６
std::uniform_int_distribution<int> dist(1, 6);

//サイコロ振る関数
typedef int (*DiceDecision)(int*);

// サイコロを振る関数
int rollDice(int* result) {
    *result = dist(random);
    return *result;
}

void showDot() {
    printf(".");
}

void SetTimeout(void (*func)()) {
    printf(".");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 3秒待機

}

//サイコロゲーム関数
void PlayDiceGame(std::function<int(int*)>diceDecisionFunc) {
    printf("奇数か偶数か当ててください(奇数:1、偶数:2)\n");
    int answer;
    scanf_s("%d", &answer); // 奇数偶数を当ててもらう

    int result;

    printf("正解は");
    for (int i = 0; i < 3; ++i) {
        SetTimeout(showDot);
    }
    printf("\n");

    diceDecisionFunc(&result); //コールバック関数
    printf("出目は %d です。\n", result);

    // 判定
    bool isOdd = result % 2 != 0; // 奇数かどうかの判定
    if ((answer == 1 && isOdd) || (answer == 2 && !isOdd)) {
        printf("正解です\n");
    }
    else {
        printf("不正解です\n");
    }
}

int main() {
    std::function<int(int*)>function = [](int* i) {return rollDice(i);};

    // ゲームを開始
    PlayDiceGame(function);


    return 0;
}
