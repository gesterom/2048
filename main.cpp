#include <iostream>
#include <Controler.h>
#include <termios.h>

using namespace std;

int main()
{
    cout << "wsad and q to exit. You must press enter to accepted\n" << endl;
    Controler controler;

    string input="sss";
    getline(cin,input);
    char c = input.c_str()[0];
//    int i=0;
    while(!controler.get_input(c))
    {
        controler.print();
        string input="";
        getline(cin,input);
        c = input.c_str()[0];
    }
    return 0;
}
