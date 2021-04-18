//King is an (Þah);
#include "chessman.h"
#pragma once


class King : public ChessMan {
public:

	King(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();

};