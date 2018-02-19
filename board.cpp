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

bool Board::valid_move(int number){
	if(the_board[number] != " X " && the_board[number] != " O "){
		return true;
	}
	else if(number > 56){
		cout << "returned false\n";
		return false;
	}
	else{
		return false;
	}
}

void Board::start(){
	int move = 0;
	int turn = 2;
	Player A("X");
	Player B("O");
	do{
		if(turn % 2 == 0){
			//subtracts 1 to because of array offset
			move = A.get_move() - 1;
			while(valid_move(move)){
				move += 7;
				if(move >= 56){
					break;
				}
			}
			
			move -= 7;
			cout << move << endl;
			the_board[move] = " X ";
			draw_board();
		}
		else{
			//subtracts 1 to because of array offset
			move = B.get_move() - 1;
			while(valid_move(move)){
				move += 7;
				if(move >= 56){
					break;
				}
			}
			move -= 7;
			cout << move << endl;
			the_board[move] = " O ";
			draw_board();
		}
		turn++;
	}while(turn < 22);
}