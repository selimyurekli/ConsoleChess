#pragma once


class ChessMan{

protected:
	int location_x;
	int location_y;
	int initial_x;
	int initial_y;

public:
	//private, inheritance taraf�ndan eri�ilemez, fakat protected eri�ebilir. 
	ChessMan();
	ChessMan(int initial_x, int initial_y);
	void getLocation_X();	
	void getLocation_Y();
	void setLocation_X();
	void setLocation_Y();
	void move();
	void remove();
	void start();



};