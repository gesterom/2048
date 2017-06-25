#include "Controler.h"
#include <iostream>

Controler::Controler()
{
    //ctor
}

Controler::~Controler()
{
    //dtor
}
void Controler::print(){
    board.print();
    std::cout<<std::endl;
}
bool Controler::get_input(char input_key){
    switch(input_key){
    case 'w':
        board.up();
        return false;
    case 's':
        board.down();
        return false;
    case 'a':
        board.left();
        return false;
    case 'd':
        board.right();
        return false;
    case 'q':
        return true;
    default:
        std::cout<<"Wrong input!!! Control key wsad press 'q' to exit \n";
        return false;
    }
}
