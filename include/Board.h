#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        void up();
        void down();
        void left();
        void right();

        void print();
        //FIXME
        void new_item();

        virtual ~Board();

    protected:

    private:
        int tab[4][4];

};

#endif // BOARD_H
