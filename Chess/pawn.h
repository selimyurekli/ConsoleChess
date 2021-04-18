//Pawn is an (Piyon);
#include "chessman.h"
#pragma once


class Pawn : public ChessMan {
public:

	Pawn(int initial_x, int initial_y);
	void getLocation_X();
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move(int new_loc_x, int new_loc_y);
	void remove();
	void start();

};