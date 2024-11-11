#include <stdio.h>
#include<memory>

/// class
#include"Circle.h"
#include"Rectangle.h"

int main() {
    /// 生成
    std::unique_ptr<Rectangle>rectangle = std::make_unique<Rectangle>();
    std::unique_ptr<Circle>circle = std::make_unique<Circle>();

    ///値セット
    rectangle->SetHeigth(10);
    rectangle->SetWidth(5);

    circle->SetRadius(6);

    ///　計算
    rectangle->Size();
    circle->Size();

    ///　結果表示
    rectangle->Draw();
    circle->Draw();


    return 0;
}
