#include<iostream>

using namespace std;

struct Rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;	
    Rectangle(int xa, int ya, int xb, int yb):
        x1(xa), 
        y1(ya),
        x2(xb),
        y2(yb)
        {}	
};


/*

0 10 10 0
5 5 15 0

*/



int main(int argc, char* argv[])
{
    cout << "Hello World" << endl;
    
    Rectangle ra(0, 10, 10, 0), rb(5, 5, 15, 0);
    
    if (ra.x2 > rb.x1 && ra.y1 > rb.y2 )
    
    
    
    cout << "Hello World" << endl;
    
    return 0;
}
