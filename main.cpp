#include <iostream>
#include <Board.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Board b;
    b.new_item();
    b.print();
    cout<<endl;
    b.right();
    b.print();
    cout<<endl;
    b.left();
    b.print();
    cout<<endl;
    b.up();
    b.print();
    cout<<endl;
    b.down();
    b.print();
    cout<<endl;
    return 0;
}
