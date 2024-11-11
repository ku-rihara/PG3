#pragma once

class IShape {
protected:
	float area_;
public:

	virtual void Size()=0;
	virtual void Draw()=0;
};