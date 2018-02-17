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
    
    vector<bool> vb(N+1, false);
    
    //cout << "trans=" << trans << endl;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] > 0 && A[i] < N+1)
        {
            vb[A[i]-1] = true;
        }

    }

    int missNumber = -1;
    for (int i = 0; i < N+1; ++i)
    {
        if (vb[i] == false)
        {
            missNumber = i +1;
            break;
        }
    }
    
    return missNumber;
    
}


int main(int argc, char* argv[])
{
	int a[] = {2147483646};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}





