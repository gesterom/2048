#include "Board.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

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
    new_item();
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
    new_item();
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
    new_item();
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
    new_item();
}

void Board::new_item(){
//    struct pos{int x;int y;};
//    std::vector<pos> v;
//    for(int i=0;i<4;i++){
//        for(int j=0;j<4;j++){
//            if(tab[i][j]==0){
//                pos temp;
//                temp.x = i;
//                temp.y = j;
//                v.push_back(temp);
//            }
//        }
//    }
//    int m = rand()%v.size();
//    pos temp2 = v[m];
//    tab[temp2.x][temp2.y] = 2*(rand()%2+1);
tab[1][1]=2;
}
