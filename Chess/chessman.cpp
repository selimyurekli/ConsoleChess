#pragma once
#include "types.cpp"
#include "map.cpp"

class Chessman:public Pawn, public Castle, public Knight, public Bishop,public Queen,public King {
	int type;
public:
	
	Chessman() { this->type = 0; };
	Chessman(int type) { this->type = type;};
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn,bool isStart) {
		switch (this->type)
		{
		case 1:  return Pawn::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 2:  return Castle::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 3:  return Knight::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 4:  return Bishop::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 5:  return Queen::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 6:  return King::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 1, isStart); break;
		case 7:  return Pawn::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;
		case 8:  return Castle::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;
		case 9:  return Knight::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;
		case 10: return Bishop::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;
		case 11: return Queen::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;
		case 12: return King::eatAndMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol, 2, isStart); break;

		default:
			break;
		}
	};

};