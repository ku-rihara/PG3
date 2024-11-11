#include"Circle.h"

#include <cmath>
#include <stdio.h>


void Circle::Size() {

	area_ = 3.14f*std::powf(radius_,2);
};
void Circle::Draw() {
	printf("円の面積は:%3.2fです", area_);
};