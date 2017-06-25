#ifndef CONTROLER_H
#define CONTROLER_H

#include <Board.h>

class Controler
{
    public:
        Controler();
        bool get_input(char);
        void print();
        virtual ~Controler();

    protected:

    private:
        Board board;
};

#endif // CONTROLER_H
