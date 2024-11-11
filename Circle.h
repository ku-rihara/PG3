#pragma once

#include"IShape.h"

class Circle :public IShape {
private:
	float radius_;
public:
	void Size()override;
	void Draw()override;

	/// setter
	void SetRadius(float rad) { radius_ = rad; }
};