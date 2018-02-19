#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <string>
using namespace std;

class Player{
private:
	string color;
	int move;
public:
	
	//constructor
	Player(string);
	
	//gets the move for the player
	int get_move();
	

};




#endif