#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//
// Codility Question
// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/
// 
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int gmin = INT_MAX;
    int gmax = 0;
    int N = A.size();
    for (int i = 0; i < N; ++i)
    {
        gmin = min(gmin, A[i]);
        gmax = max(gmax, A[i] - gmin);
    }

    return gmax;
}


int main()
{
	constexpr N = 10;
	static_assert(true, "Hello");
    vector<int> A = { 23171, 21011,  21123,  21366,  21013,  21367 };
    int res = solution(A);

    cout << "Res=" << res << endl;

    return 0;
}

