#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//
// Codility Question
// 

/*
TBD: I did not understand why is the max compared with 0(but not A[i]) in below code

k1[i] = max(k1[i-1]+A[i], 0);
k2[i] = max(k2[i+1]+A[i], 0);
Now I understand why k1[i-1]+A[i] compared with 0 – If A[i] can contribute 
to the sequence we add A[i] else we set the maxsum upto ‘i’ as 0. 
Samething is true for the k2.

The comments part of this link has good explanation 
https://rafal.io/posts/codility-max-double-slice-sum.html
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    vector<int> k1(N);
    vector<int> k2(N);

    k1[0] = 0;
    for (int i = 1; i < N; i++)
    {
        k1[i] = max(k1[i - 1] + A[i], 0);
    }

    k2[N - 1] = 0;
    for (int i = N - 2; i > 0; --i)
    {
        k2[i] = max(k2[i + 1] + A[i], 0);
    }

    int maxSum = 0;
    for (int i = 1; i < N - 1; i++)
    {
        maxSum = max(maxSum, k1[i - 1] + k2[i + 1]);
    }
    return maxSum;
}



int main()
{
    vector<int> A = { 3,2,6,-1,4,5,-1,2 };
    int res = solution(A);

    cout << "Res=" << res << endl;

    return 0;
}

