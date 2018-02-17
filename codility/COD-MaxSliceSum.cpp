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
    int N = A.size();
    vector<int> k1(N);
    vector<int> k2(N);
    
    k1[0]=0;
    for (int i = 1; i < N; i++)
    {
        k1[i] = max(k1[i-1]+A[i], A[i]);
    }
    
    k2[N-1]=0;
    for (int i = N-2; i > 0; --i)
    {
        k2[i] = max(k2[i+1]+A[i], A[i]);
    }
    
    int maxSum = 0;
    for(int i =1; i < N-1; i++)
    {
       maxSum = max(maxSum, k1[i-1]+k2[i+1]);
    }
    return maxSum;
}


int main(int argc, char* argv[])
{
	int a[] = {2147483646};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}









