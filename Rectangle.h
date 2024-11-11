#pragma once

#include"IShape.h"

class Rectangle :public IShape {
private:
	float heigth_;
	float width_;
public:
	void Size()override;
	void Draw()override;

	void SetHeigth(float hei) { heigth_ = hei; }
	void SetWidth(float wid) { width_ = wid; }
};