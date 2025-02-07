#include <stdio.h>
#include<iostream>
//std
#include <chrono>
#include<string>
//class
#include"Enemy.h"

int main() {
   
    std::string a(100000,'a');
   
    // コピー
    auto startCopy = std::chrono::high_resolution_clock::now();
    std::string copy = a;
    auto endCopy = std::chrono::high_resolution_clock::now();

    // 移動
    auto startMove = std::chrono::high_resolution_clock::now();
    std::string move = std::move(a);
    auto endMove = std::chrono::high_resolution_clock::now();
  

    std::cout << "コピーの時間: "
        << std::chrono::duration_cast<std::chrono::microseconds>(endCopy - startCopy).count()
        << " μs\n";

    std::cout << "移動の時間: "
        << std::chrono::duration_cast<std::chrono::microseconds>(endMove - startMove).count()
        << " μs\n";

    return 0;
}
