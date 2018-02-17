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


#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int getMax(vector<int> v)
{
    int N = v.size();
    int max = v[0];
    for( int i =1; i < N; i++)
    {
        if(v[i] > max)
            max = v[i];
    }
    
    return max;
}

vector<int> buildCache(int aM, int bM)
{
    vector<int> cache(aM);
    cache[1] = 1;   // Although not needed
    cache[2] = 2;
    
    for (int i = 3; i <= aM; ++i)
    {
        cache[i] = (cache[i-1] + cache[i-2]) % ((int)pow((int)2,(int)bM));
    }
    
    return cache;
}

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    int aMax = getMax(A);    
    int bMax = getMax(B);
    vector<int> cache = buildCache(aMax, bMax);
    
    int N = A.size();
    vector<int> result(N);
    for (int i = 0; i < N; ++i)
    {
        result[i] = cache[A[i]] % (int)pow((int)2, (int)B[i]);
    }
    
    return result;
}



int main(int argc, char* argv[])
{
	int a[] = {4, 4, 5, 5, 1};
	int b[] = {3, 2, 4, 3, 1};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	vector<int> vb(b, b + sizeof(b)/sizeof(b[0]));
	
	vector<int> vc = solution(va, vb);
	
	cout << "Result=" << vc.size() << endl;	
}





