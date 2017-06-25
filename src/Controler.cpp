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
void Controler::print()
{
    board.print();
    std::cout<<std::endl;
}
bool Controler::get_input(char input_key)
{
    bool b;
    switch(input_key)
    {
    case 'w':
        b = board.up();
        if(board.win())
        {
            std::cout<<"YOU WON\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(board.blocked())
        {
            std::cout<<"Game Over!!!\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(b) board.new_item();
        return false;
    case 's':
        b = board.down();
        if(board.win())
        {
            std::cout<<"YOU WON\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(board.blocked())
        {
            std::cout<<"Game Over!!!\YOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(b)
        {
            board.new_item();
        }
        return false;
    case 'a':
        b = board.left();
        if(board.win())
        {
            std::cout<<"YOU WON\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(board.blocked())
        {
            std::cout<<"Game Over!!!\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(b) board.new_item();
        return false;
    case 'd':
        b = board.right();
        if(board.win())
        {
            std::cout<<"YOU WON\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(board.blocked())
        {
            std::cout<<"Game Over!!!\nYOUR SCORE: "<<board.get_score()<<std::endl;
            return true;
        }
        if(b) board.new_item();
        return false;
    case 'q':
        return true;
    default:
        std::cout<<"Wrong input!!! Control key wsad press 'q' to exit \n";
        return false;
    }
}
