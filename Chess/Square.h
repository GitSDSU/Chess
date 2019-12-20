#pragma once

#include "Constants.h"

class Square
{
public:
	Square(Pos);
	~Square();
	void Display_Square();

private:
	Pos position;
};

