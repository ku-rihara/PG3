#include <stdio.h>
//std
#include <chrono>
#include <thread>
//class
#include"Enemy.h"

int main() {
   
    Enemy* enemy = new Enemy();
 
    while (true) {  
        // フレームごとに敵の状態を更新
        enemy->Update();

        _Thrd_sleep_for(1);//毎フレーム処理    
    }

    return 0;
}
