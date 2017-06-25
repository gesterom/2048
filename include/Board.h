#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        bool up();
        bool down();
        bool left();
        bool right();

        void print();

        //FIXME
        void new_item();

        virtual ~Board();

    protected:

    private:
        int tab[4][4];

        bool gravity_up();
        bool compres_up();

        bool gravity_down();
        bool compres_down();

        bool compres_left();
        bool gravity_left();

        bool compres_right();
        bool gravity_right();

};

#endif // BOARD_H
