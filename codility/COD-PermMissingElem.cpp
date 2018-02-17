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
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long N = A.size();
    long sum = 0;
    for (long i = 0; i < N; ++i)
    {
    	sum += A[i];
	}
	
	long rSum = (N+1) * (N+2) / 2;
	int diff = rSum - sum;
	
	return diff;
    
}


int main(int argc, char* argv[])
{
	int a[] = {1,2,4,3,6};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}





