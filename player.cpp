#include "player.h"

Player::Player(string cl) {
	color = cl;
};

int Player::get_move(){
	cout << "select a slot to make your move: 1..7: \n";
	cin >> move;
	return move;
}