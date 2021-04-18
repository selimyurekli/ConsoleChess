//Bishop is an (Fil);
#include "chessman.h"
#pragma once


class Bishop : public ChessMan {
public:

	Bishop(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();

};
