#include "iostream"
#include "string"
#include "fstream"
#include "map.cpp"
#include "types.cpp"
#include "chessman.cpp"
#define SIZE 8
using namespace std;
class Game {
public:
		Game() { turn = 1; };
		
		void startGame() {
			// space  = 0, 
			// pawn_1 = 1, castle_1 = 2, knight_1 = 3, bishop_1 = 4,  queen_1  = 5,  king_1=6, 
			// pawn_2 = 7, castle_2 = 8, knight_2 = 9, bishop_2 = 10, queen_2 = 11,  king_2 = 12
			char toSelectRow; int toSelectCol;
			char toPutRow; int toPutCol;
			
			bool isOkey = false;
			pair<bool, bool> p = checkIsKingAlive();
			chessBoard.printMap();
			Chessman* c;
			bool isStart = true;
			while (p.first && p.second) {
				cout << "Turn: player "<<turn << endl;
				cout << "Please type the chessman's location as letter and number." << endl;


				cin >> toSelectRow >> toSelectCol;
				toSelectCol = toupper(toSelectCol);

				int typeOfChess = chessBoard.getLocation(toSelectRow - 65, toSelectCol);

				if (typeOfChess > 0&& typeOfChess > 6 * (turn-1) && typeOfChess <= 6 * turn) {
					//check whose turn is;
					cout << "Please enter where would you like to put chessman" << endl;
					cin >> toPutRow >> toPutCol;
					toPutCol = toupper(toPutCol);
					//create an object of chess;
					c = new Chessman(typeOfChess);
					if (c->eatAndMove(chessBoard, toPutRow-65, toPutCol, toSelectRow-65, toSelectCol, turn,isStart)) {
						if (isStart && turn == 2)
							isStart = false;
						turn = (turn == 1) ? 2 : 1;
					}
					else {
						cout << "You can not move there" << endl;
					}
					
				}
				else {
					cout << "You can't chose space or the other player's chessman place" << endl;
				}

				p = checkIsKingAlive();
				chessBoard.printMap();
				
 			}
			cout << endl << endl << endl;
			if (p.first) cout << "Player 1 won!!!!!!!";
			else if (p.second) cout << "Player 2 won!!!!!!!";






		}
private: 
	Map chessBoard;
	int turn ;

	pair<bool, bool> checkIsKingAlive() {
		bool isFirstFound = false;
		bool isSecondFound = false;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (chessBoard.chess[i][j] == 6) isFirstFound = true;
				else if (chessBoard.chess[i][j] == 12) isSecondFound= true;
		pair<bool, bool> p(isFirstFound, isSecondFound);
		return p;
	}

};


int main() {
	Game game;
	game.startGame();
	return 0;
}