#include "Board.h"
#include <iostream>

Board::Board()
{
    //ctor
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tab[i][j]=0;
        }
    }
}

Board::~Board()
{
    //dtor
}
void Board::print(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<tab[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
void Board::right(){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(tab[i][j]==tab[i][j+1] || tab[i][j+1]==0){
                tab[i][j+1]+=tab[i][j];
                tab[i][j]=0;
            }
        }
    }
}
void Board::left(){
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(tab[i][j]==tab[i][j-1] || tab[i][j-1]==0){
                tab[i][j-1]+=tab[i][j];
                tab[i][j]=0;
            }
        }
    }
}
void Board::up(){
    for(int i=3;i>0;i--){
        for(int j=0;j<3;j++){
            if(tab[i][j]==tab[i-1][j] || tab[i-1][j]==0){
                tab[i-1][j]+=tab[i][j];
                tab[i][j]=0;
            }
        }
    }
}

void Board::down(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(tab[i][j]==tab[i+1][j] || tab[i+1][j]==0){
                tab[i+1][j]+=tab[i][j];
                tab[i][j]=0;
            }
        }
    }
}

void Board::new_item(){
    tab[1][2]=2;
}
