//Queen is an (Vezir);
#include "chessman.h"
#pragma once


class Queen : public ChessMan {
public:

	Queen(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();

};