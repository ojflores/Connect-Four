#include "board.h"

Board::Board() {};

void Board::ini_drawBoard(){
	int i;
	for(i = 0; i < BOARD_SIZE; i++){
		the_board[i] = " - ";
		cout << the_board[i];
		if((i+1) % 7 == 0){
			cout << "\n";
		}
	}
}

void Board::draw_board(){
	int i;
	for(i = 0; i < BOARD_SIZE; i++){
		cout << the_board[i];
		if((i+1) % 7 == 0){
			cout << "\n";
		}
	}
	
}

void Board::start(){
	int turn = 2;
	Player A("X");
	Player B("O");
	if(turn % 2 == 0){
		A.get_move();
	}
	else{
		B.get_move();
	}
}