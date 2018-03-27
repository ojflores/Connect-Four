#include "board.h"
#define MAX_MOVES 58

Board::Board() {};

bool win(int turn){
	int counter = 0;
	string piece;
	if(turn % 2 == 0){
		piece = " X ";
	}
	else{
		piece = " O ";
	}
	while(counter < turn-2){
		//got bored and wrote this in
		//left off here, erase that incrementation, it does nothing
		counter++;
	}
	
	
	return false;
}

void Board::ini_drawBoard(){
	int i;
	for(i = 0; i < BOARD_SIZE; i++){
		the_board[i] = " - ";
		moves_made[i] = 0;
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
	int weight[7] = {0, 0, 0, 0, 0, 0, 0};
	Player A("X");
	Player B("O");
	do{
		if(turn % 2 == 0){
			//subtracts 1 to because of array offset
			move = A.get_move() - 1;
			weight[move] += 1;
			cout << weight[move] << endl;
			//checks if you have too many pieces in one row
			while(weight[move] > 8){
				move = A.get_move() - 1;
				cout << "the row you have selected is full\n";
			}
			while(valid_move(move)){
				move += 7;
				if(move >= 56){
					break;
				}
			}
			
			move -= 7;
			cout << move << endl;
			the_board[move] = " X ";
			//keeps track of the moves made to try and make win function a little more efficient
			moves_made[turn - 2] = move;
			//cout << "these are the moves" << moves_made[turn - 2] << endl;
			draw_board();
		}
		else{
			//subtracts 1 to because of array offset
			move = B.get_move() - 1;
			weight[move] += 1;
			cout << weight[move] << endl;
			//checks if you have too many pieces in one row
			while(weight[move] > 8){
				move = A.get_move() - 1;
				cout << "the row you have selected is full\n";
			}
			while(valid_move(move)){
				move += 7;
				if(move >= 56){
					break;
				}
			}
			move -= 7;
			cout << move << endl;
			the_board[move] = " O ";
			//keeps track of the moves made to try and make win function a little more efficient
			moves_made[turn - 2] = move;
			//cout << "these are the moves" << moves_made[turn - 2] << endl;
			draw_board();
		}
		turn++;
	}while(turn < MAX_MOVES);
}