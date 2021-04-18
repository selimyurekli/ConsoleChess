//knight is an (AT);
#include "chessman.h"
#pragma once


class Knight : public ChessMan {
public:
	
	Knight(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();

};