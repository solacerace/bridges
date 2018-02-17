#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;
int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    
    int count  = (Y-X)/D;
    int mod = (Y-X)%D;
    
    if (mod != 0)
    {
        count++;
    }
   
    return count;
    
}


int main(int argc, char* argv[])
{
	
	int res = solution(10,85,30);
	
	cout << "Result=" << res << endl;	
}





