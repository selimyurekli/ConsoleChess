//abstract
#pragma once
#include "iostream"
#include "map.cpp"
#include "math.h"


class TypeClass {
public:
	virtual bool eatAndMove(Map& map, int ToWhereRow,int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) = 0;
	

};

class Bishop :virtual public TypeClass {
private:
	int type;
public:
	Bishop() { this->type = 4; };
	Bishop(int turn) { this->type = 4 + 6 * (turn - 1); };
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) {
		if (checkCanBishopMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) {
			if (turn == 1 && map.getLocation(ToWhereRow, ToWhereCol) < 7 && map.getLocation(ToWhereRow, ToWhereCol) > 0) return false;
			if (turn == 2 && map.getLocation(ToWhereRow, ToWhereCol) > 6) return false;
			map.setLocation(4 + 6 * (turn - 1), ToWhereRow, ToWhereCol);
			map.setLocation(0, FromWhereRow, FromWhereCol);

			return true;
		}
		else return false;

	}
	static bool checkCanBishopMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol) {
		if (abs(ToWhereRow - FromWhereRow) == abs(ToWhereCol - FromWhereCol)) {
			if (ToWhereRow > FromWhereRow && ToWhereCol> FromWhereCol) {
				
				for (int i = 1; i < abs(ToWhereRow - FromWhereRow); i++) {
					if (map.getLocation(FromWhereRow+i, FromWhereCol+i) != 0) return false;
				}
				return true;

			}
			else if (ToWhereRow > FromWhereRow && ToWhereCol < FromWhereCol) {

				for (int i = 1; i < abs(ToWhereRow - FromWhereRow); i++) {
					if (map.getLocation(FromWhereRow + i, FromWhereCol - i) != 0) return false;
				}
				return true;

			}
			else if (ToWhereRow < FromWhereRow && ToWhereCol > FromWhereCol) {

				for (int i = 1; i < abs(ToWhereRow - FromWhereRow); i++) {
					if (map.getLocation(FromWhereRow - i, FromWhereCol + i) != 0) return false;
				}
				return true;

			}
			else if (ToWhereRow < FromWhereRow && ToWhereCol < FromWhereCol) {

				for (int i = 1; i < abs(ToWhereRow - FromWhereRow); i++) {
					if (map.getLocation(FromWhereRow - i, FromWhereCol - i) != 0) return false;
				}
				return true;
			}
			else {
				return false;
			}
		}	
		else {
			return false;
		}
		
	}


};

class Knight :virtual public TypeClass {
private:
	int type;
public:
	Knight() { this->type = 3; };
	Knight(int turn) { this->type = 3 + 6 * (turn - 1); };
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) {
		if (checkCanKnightMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) {
			if (turn == 1 && map.getLocation(ToWhereRow, ToWhereCol) < 7 && map.getLocation(ToWhereRow, ToWhereCol) > 0) return false;
			if (turn == 2 && map.getLocation(ToWhereRow, ToWhereCol) > 6) return false;
			map.setLocation(3 + 6 * (turn - 1), ToWhereRow, ToWhereCol);
			map.setLocation(0, FromWhereRow, FromWhereCol);

			return true;
		}
		else return false;

	}
	bool checkCanKnightMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol) {
		if (ToWhereCol - FromWhereCol == 1 || ToWhereCol - FromWhereCol == -1) {
			if (ToWhereRow - FromWhereRow == 2 || ToWhereRow - FromWhereRow == -2) {
				return true;
			}
			else return false;

		}
		else if (ToWhereCol - FromWhereCol == 2 || ToWhereCol - FromWhereCol == -2) {
			if (ToWhereRow - FromWhereRow == 1 || ToWhereRow - FromWhereRow == -1) {
				return true;
			}
			else return false;
		}
		else return false;

		


	}


};

class Castle :virtual public TypeClass {
private:
	int type;
public:
	Castle() { this->type = 2; };
	Castle(int turn) { this->type = 2 + 6 * (turn - 1); };
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) {
		if (checkCanCastleMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) {
			if (turn == 1 && map.getLocation(ToWhereRow, ToWhereCol) < 7 && map.getLocation(ToWhereRow, ToWhereCol) > 0) return false;
			if (turn == 2 && map.getLocation(ToWhereRow, ToWhereCol) > 6) return false;
			map.setLocation(2+6*(turn-1), ToWhereRow, ToWhereCol);
			map.setLocation(0, FromWhereRow, FromWhereCol);

			return true;
		}
		else return false;

	}
	static bool checkCanCastleMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol) {
		if (ToWhereCol - FromWhereCol == 0) {
			//Up and down
			if (ToWhereRow > FromWhereRow) {
				//down
				for (int i = FromWhereRow + 1; i < ToWhereRow; i++) {

					if (map.getLocation(i, ToWhereCol) != 0) return false;
				}
				return true;
			}
			else {
				//up
				for (int i = FromWhereRow - 1; i > ToWhereRow ; i--) {
					if (map.getLocation(i, ToWhereCol) != 0) return false;
				}
				return true;
			}

		}
		else if (ToWhereRow - FromWhereRow == 0) {
			//Right and left
			if (ToWhereCol > FromWhereCol) {
				//right
				for (int i = FromWhereCol + 1; i < ToWhereCol; i++) {
					if (map.getLocation(ToWhereRow, i) != 0) return false;
				}
				return true;
			}
			else {
				//left
				for (int i = FromWhereCol - 1; i > ToWhereCol; i--) {
					if (map.getLocation(ToWhereRow, i) != 0) return false;
				}
				return true;
			}

		}
		else {
			return false;
		}


	}


};

class Pawn:virtual public TypeClass{
private: 
	int type = 1;
public:
	Pawn() { this->type = 1; };

	Pawn(int turn) { this->type = 1+6*(turn-1); };
	bool eatAndMove(Map &map, int ToWhereRow , int ToWhereCol, int FromWhereRow, int FromWhereCol,int turn, bool isStart) {
		if (turn == 1) {
			if (isStart) {
				if ((ToWhereRow - FromWhereRow == 2 || ToWhereRow - FromWhereRow == 1) && ToWhereCol - FromWhereCol == 0) {
					//player 1 can go attack.//only move

					//move
					if (map.chess[ToWhereRow][ToWhereCol] == 0)
					{
						map.chess[ToWhereRow][ToWhereCol] = 1;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;
				}

				else if (ToWhereRow - FromWhereRow == 1 && (ToWhereCol - FromWhereCol == 1 || ToWhereCol - FromWhereCol == -1)) {
					//eat
					if (map.chess[ToWhereRow][ToWhereCol] != 0 && map.chess[ToWhereRow][ToWhereCol] > 6) {
						map.chess[ToWhereRow][ToWhereCol] = 1;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;
				}
			}
			else{
				if (ToWhereRow - FromWhereRow == 1 && ToWhereCol - FromWhereCol == 0) {
					//player 1 can go attack.//only move

					//move
					if (map.chess[ToWhereRow][ToWhereCol] == 0)
					{
					 map.chess[ToWhereRow][ToWhereCol] = 1;
					 map.chess[FromWhereRow][FromWhereCol] = 0;
					 return true;
					}
					else return false;
				}
			
				else if (ToWhereRow - FromWhereRow == 1 && (ToWhereCol - FromWhereCol == 1|| ToWhereCol - FromWhereCol == -1)) {
						//eat
					if (map.chess[ToWhereRow][ToWhereCol] != 0 && map.chess[ToWhereRow][ToWhereCol]>6) {
						map.chess[ToWhereRow][ToWhereCol] = 1;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;
				}
			}

		}
		else if (turn == 2) {
			if (isStart) {
				if ((ToWhereRow - FromWhereRow == -2||ToWhereRow - FromWhereRow == -1)&& ToWhereCol - FromWhereCol == 0) {
					//player 2 can go attack.//only move

					//move
					if (map.chess[ToWhereRow][ToWhereCol] == 0)
					{
						map.chess[ToWhereRow][ToWhereCol] = 7;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;
				}
				else if (ToWhereRow - FromWhereRow == -1 && (ToWhereCol - FromWhereCol == 1 || ToWhereCol - FromWhereCol == -1)) {
					//eat
					if (map.chess[ToWhereRow][ToWhereCol] != 0) {
						map.chess[ToWhereRow][ToWhereCol] = 7;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;


				}
			}else{
				if (ToWhereRow - FromWhereRow == -1 && ToWhereCol - FromWhereCol == 0) {
					//player 2 can go attack.//only move

					//move
					if (map.chess[ToWhereRow][ToWhereCol] == 0)
					{
						map.chess[ToWhereRow][ToWhereCol] = 7;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;
				}
				else if (ToWhereRow - FromWhereRow == -1 && (ToWhereCol - FromWhereCol == 1 || ToWhereCol - FromWhereCol == -1)) {
					//eat
					if (map.chess[ToWhereRow][ToWhereCol] != 0) {
						map.chess[ToWhereRow][ToWhereCol] = 7;
						map.chess[FromWhereRow][FromWhereCol] = 0;
						return true;
					}
					else return false;


				}
			
			}
		}

		
		return false;
	
	}

};





class Queen :virtual public TypeClass {
private:
	int type;
public:
	Queen() { this->type = 5; };
	Queen(int turn) { this->type = 5 + 6 * (turn - 1); };
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) {
		if (checkCanQueenMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) {
			if (turn == 1 && map.getLocation(ToWhereRow, ToWhereCol) < 7 && map.getLocation(ToWhereRow, ToWhereCol) > 0) return false;
			if (turn == 2 && map.getLocation(ToWhereRow, ToWhereCol) > 6) return false;
			map.setLocation(5 + 6 * (turn - 1), ToWhereRow, ToWhereCol);
			map.setLocation(0, FromWhereRow, FromWhereCol);

			return true;
		}
		else return false;

	}
	bool checkCanQueenMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol) {
		if (Bishop::checkCanBishopMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) return true;
		else if (Castle::checkCanCastleMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) return true;
		else return false;

	}


};
class King :virtual public TypeClass {
private:
	int type;
public:
	King() { this->type = 6; };
	King(int turn) { this->type = 6 + 6 * (turn - 1); };
	bool eatAndMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol, int turn, bool isStart) {
		if (checkCanKingMove(map, ToWhereRow, ToWhereCol, FromWhereRow, FromWhereCol)) {
			if (turn == 1 && map.getLocation(ToWhereRow, ToWhereCol) < 7 && map.getLocation(ToWhereRow, ToWhereCol) > 0) return false;
			if (turn == 2 && map.getLocation(ToWhereRow, ToWhereCol) > 6) return false;
			map.setLocation(6 + 6 * (turn - 1), ToWhereRow, ToWhereCol);
			map.setLocation(0, FromWhereRow, FromWhereCol);

			return true;
		}
		else return false;

	}
	bool checkCanKingMove(Map& map, int ToWhereRow, int ToWhereCol, int FromWhereRow, int FromWhereCol) {
		if (abs(ToWhereRow - FromWhereRow) == 1 && abs(ToWhereCol - FromWhereCol) == 0) return true;
		else if (abs(ToWhereRow - FromWhereRow) == 0 && abs(ToWhereCol - FromWhereCol) == 1) return true;
		else if (abs(ToWhereRow - FromWhereRow) == 1 && abs(ToWhereCol - FromWhereCol) == 1) return true;
		else return false;

	}


};
