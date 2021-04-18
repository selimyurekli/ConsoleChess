//Castle is an (Kale);
#include "chessman.h"
#pragma once


class Castle : public ChessMan {
public:

	Castle(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();

};