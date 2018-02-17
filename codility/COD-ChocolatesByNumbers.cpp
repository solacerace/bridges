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


long gcd(long a, long b)
{
	if (a%b ==0 )
		return b;
	else
		return gcd(b, a%b);
}    
    
long mysolution(long N, long M) {
    // write your code in C++14 (g++ 6.2.0)
    long lcm = M*N/gcd(N,M);
    return lcm/M;
}

int solution(int N, int M) {
	return mysolution(N,M);
}



int main(int argc, char* argv[])
{

	
	int res = solution(10, 4);
	
	
	cout << "Result=" << res << endl;	
}



