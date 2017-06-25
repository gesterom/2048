#include "Board.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

Board::Board() {
	//ctor
	score = 0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			tab[i][j]=0;
		}
	}
}

Board::~Board() {
	//dtor
}
void Board::print() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			std::cout<<tab[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Board::new_item() {
	struct pos {
		int x;
		int y;
	};
	std::vector<pos> v;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(tab[i][j]==0) {
				pos temp;
				temp.x = i;
				temp.y = j;
				v.push_back(temp);
			}
		}
	}
	int m = rand()%v.size();
	pos temp2 = v[m];
	tab[temp2.x][temp2.y] = 2*(rand()%2+1);
}
bool Board::down() {
	bool b =false;
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	bool a = compres_down();
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	b = gravity_down()|| b;
	std::cout<<b<<std::endl;
	if(a||b)score++;
	return a || b;
}
bool Board::compres_down() {
	bool ret = false;
	for(int i=3; i>0; i--) {
		for(int j=0; j<4; j++) {
			if(tab[i][j]==tab[i-1][j] && tab[i][j]!=0) {
				tab[i][j]+=tab[i-1][j];
				tab[i-1][j]=0;
				ret=true;
			}
		}
	}
	return ret;
}

bool Board::gravity_down() {
	bool ret = false;
	for(int i=2; i>=0; i--) {
		for(int j=0; j<4; j++) {
			if(tab[i+1][j]==0 && tab[i][j]!=0) {
				tab[i+1][j]=tab[i][j];
				tab[i][j]=0;
				ret=true;
			}
		}
	}
	return ret;
}

bool Board::up() {
	bool b = false;
	b =gravity_up()|| b;
	b =gravity_up()|| b;
	b =gravity_up()|| b;
	b =gravity_up()|| b;
	bool a = compres_up();
	b =gravity_up()|| b;
	b =gravity_up()|| b;
	b =gravity_up()|| b;
	b =gravity_up()|| b;

	if(a||b)score++;
	return a||b;
}

bool Board::gravity_up() {
	bool ret = false;
	for(int i=1; i<=3; i++) {
		for(int j=0; j<4; j++) {
			if(tab[i-1][j]==0 && tab[i][j]!=0) {
				tab[i-1][j]=tab[i][j];
				tab[i][j]=0;
				ret=true;
			}
		}
	}
	return ret;
}

bool Board::compres_up() {
	bool ret = false;
	for(int i=0; i<3; i++) {
		for(int j=0; j<4; j++) {
			if(tab[i][j]==tab[i+1][j] && tab[i][j]!=0) {
				tab[i][j]+=tab[i+1][j];
				tab[i+1][j]=0;
				ret=true;
			}
		}
	}
	return ret;
}

bool Board::left() {
	bool b = false;
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	bool a = compres_left();
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	b = gravity_left()|| b;
	if(a||b)score++;
	return a||b;
}

bool Board::compres_left() {
	bool ret = false;
	for(int i=0; i<4; i++) {
		for(int j=0; j<3; j++) {
			if(tab[i][j]==tab[i][j+1] && tab[i][j]!=0) {
				tab[i][j]+=tab[i][j+1];
				tab[i][j+1]=0;
				ret = true;
			}
		}
	}
	return ret;
}
bool Board::gravity_left() {
	bool ret = false;
	for(int i=0; i<4; i++) {
		for(int j=1; j<4; j++) {
			if(tab[i][j-1]==0) {
				tab[i][j-1]=tab[i][j];
				tab[i][j]=0;
				ret = true;
			}
		}
	}
	return ret;
}
bool Board::right() {
	bool b = false;
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	bool a = compres_right();
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	b = gravity_right()|| b;
	if(a||b)score++;
	return a||b;
}
bool Board::compres_right() {
	bool ret = false;
	for(int i=0; i<4; i++) {
		for(int j=3; j>0; j--) {
			if(tab[i][j]==tab[i][j-1] && tab[i][j]!=0) {
				tab[i][j]+=tab[i][j-1];
				tab[i][j-1]=0;
				ret = true;
			}
		}
	}
	return ret;
}
bool Board::gravity_right() {
	bool ret = false;
	for(int i=0; i<4; i++) {
		for(int j=2; j>=0; j--) {
			if(tab[i][j+1]==0) {
				tab[i][j+1]=tab[i][j];
				tab[i][j]=0;
				ret = true;
			}
		}
	}
	return ret;
}
bool Board::win() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(tab[i][j]==2048) {
				return true;
			}
		}
	}
	return false;
}
bool Board::blocked() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(tab[i][j]==0) {
				return false;
			}
		}
	}
	return true;
}
int Board::get_score() {
	return score;
}
