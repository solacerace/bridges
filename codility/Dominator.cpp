#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//
// Codility Question
//https://app.codility.com/programmers/lessons/8-leader/dominator/
// 
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    int N = A.size();

    if (N == 0)
        return -1;

    // first, compute the leader
    int leader = A[0];
    int ctr = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] == leader) ctr++;
        else ctr--;
        if (ctr == 0) {
            ctr = 1;
            leader = A[i];
        }
    }

    // check if it's a leader?
    int total = 0;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == leader)
        {
            index = i;
            total++;
        }
    }

    if (total <= (N / 2)) return -1; // impossible

    return index;

}



int main()
{
    vector<int> A = { 4,3,4,4,4,2 };
    int res = solution(A);

    cout << "Res=" << res << endl;

    return 0;
}

