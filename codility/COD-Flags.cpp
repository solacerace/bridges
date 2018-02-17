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


vector<bool> createPeaks(vector<int>& A)
{
	int N = A.size();
	vector<bool> vb(N, false);
	for(int i = 1; i < N-1; ++i)
	{
		if (A[i-1] < A[i] && A[i] > A[i+1])
			vb[i] = true;
	}
	
	return vb;
}


vector<int> nextPeak(vector<int>& A)
{
	vector<bool> vb = createPeaks(A);
	int N = A.size();
	vector<int> next(N);
	next[N-1] = -1;
	for (int i = N-2; i > -1; --i)
	{
		if (vb[i] == true)
			next[i] = i;
		else
			next[i] = next[i+1];
	}
	
	return next;
}

int max(int a, int b) 
{
	if (a>b)
		return a;
	else
		return b;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    if (N < 3)
    	return 0;
    
    vector<int> next = nextPeak(A);
    int i = 1;
    int result = 0;
    
    while( (i-1)*i <= N)
    {
    	int pos = 0;
		int num = 0;	
		while(pos < N && num < i)
		{
		    pos = next[pos];
			if (pos == -1)
				break;
			num += 1;
			pos += i; // Increment pos by i
		}
		result = max(result, num);
		i += 1;
	}
    
    return result;    
}


int main(int argc, char* argv[])
{
	int a[] = {1};
	//int a[] = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}
















