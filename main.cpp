#include <stdio.h>
#include<random>
#include<thread>

 std::random_device rd;
 std::mt19937 random(rd());
 //1から６
 std::uniform_int_distribution<int> dist(1, 6); 

 //サイコロ振る関数
 typedef int (*DiceDecision)(int *);

 // サイコロを振る関数
 int rollDice(int* result) {
	 *result = dist(random);
	 return *result;
 }

 //サイコロゲーム関数
 void PlayDiceGame(DiceDecision diceDecsion) {
	 printf("奇数か偶数か当ててください(奇数:1、偶数:2)\n");
	 int answer;
     scanf_s("%d", &answer); // 奇数偶数を当ててもらう

     int result;

     printf("正解は.");
     for (int i = 0; i < 3; ++i) {
         std::this_thread::sleep_for(std::chrono::seconds(1)); // 1秒待機
         if (i < 2) {
             printf(".");
         }
         
     }
     printf("\n");

     diceDecsion(&result); //コールバック関数
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
    // 関数ポインタを設定
    DiceDecision diceDecision = rollDice;

    // ゲームを開始
    PlayDiceGame(diceDecision);


	return 0;
}
