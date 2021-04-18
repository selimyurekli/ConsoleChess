#pragma once
#include "iostream"


using namespace std;
class Map {
	
public:
	enum chessmans {
		space = 0, pawn_1 = 1, castle_1 = 2, knight_1 = 3, bishop_1 = 4, queen_1 = 5, king_1 = 6,
		pawn_2 = 7, castle_2 = 8, knight_2 = 9, bishop_2 = 10, queen_2 = 11, king_2 = 12
	};
	Map() {};
	static const int size = 8;

	int chess[size][size] = { {castle_1 ,knight_1 ,bishop_1 ,queen_1 ,king_1 ,bishop_2 ,knight_1 ,castle_1},
							  {pawn_1   ,pawn_1   ,pawn_1   ,pawn_1  ,queen_2 ,pawn_1   ,pawn_1   ,pawn_1  },
							  {space    ,space    ,space    ,space   ,space  ,space    ,space    ,space   },
							  {space    ,space    ,space    ,space   ,space  ,space    ,space    ,space   },
							  {space    ,space    ,space    ,space   ,space  ,space    ,space    ,space   },
							  {space    ,space    ,space    ,space   ,space  ,space    ,space    ,space   },
							  {pawn_2   ,pawn_2   ,pawn_2   ,pawn_2  ,pawn_2 ,pawn_2   ,pawn_2   ,pawn_2  },
							  {castle_2 ,knight_2 ,bishop_2 ,queen_2 ,king_2 ,bishop_1 ,knight_2 ,castle_2},
							 };
	
	int getLocation(int row, int column) {
		return chess[row][column];
	}
	void setLocation(int setValue, int row, int column) {
		 chess[row][column] = setValue;
	}

	void printMap() {
		cout << "      0   1   2   3   4   5   6   7" << endl;

		for (int row = 0; row < size; row++) {
			char c = row + 65;
			cout << "  "<<c<<"  ";
			for (int column = 0; column < size; column++) {
				//cout << "row:" << row << " col:" << column << "  :" << chess[row][column] << endl;
				switch (chess[row][column])
				{
				case space:cout << " __ "; break;
				case pawn_1:cout << " p1 "; break;
				case castle_1:cout << " c1 "; break;
				case knight_1:cout << " k1 "; break;
				case bishop_1:cout << " b1 "; break;
				case queen_1:cout << " q1 "; break;
				case king_1:cout << " k1 "; break;
				case pawn_2:cout << " p2 "; break;
				case castle_2:cout << " c2 "; break;
				case knight_2:cout << " k2 "; break;
				case bishop_2:cout << " b2 "; break;
				case queen_2:cout << " q2 "; break;
				case king_2:cout << " k2 "; break;
				
				default:
					break;
				}

			}
			cout << endl;
		}



	}
};