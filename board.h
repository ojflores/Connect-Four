#ifndef BOARD_H_
#define BOARD_H_
#include "player.h"
#define BOARD_SIZE 56
using namespace std;

class Board{
private:
	string the_board[56];
public:

		//constructor
		Board();
		
		//draws and initializes the board
		void ini_drawBoard();
		
		//draws the board
		void draw_board();

		//starts the game
		void start();
		
		//checks if its a valid move
		bool valid_move(int);
};




#endif

