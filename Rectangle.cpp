#include"Rectangle.h"
#include <stdio.h>


void Rectangle::Size() {
	area_ = heigth_ * width_;
};
void Rectangle::Draw() {

	printf("矩形の面積は:%3.2fです\n", area_);
};