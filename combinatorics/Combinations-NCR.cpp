#include <iostream>
#include "stdio.h"
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

using namespace std;

/* 
Citadel Questions
Program to print NCR -- All compbinations of size R from N numbers.
https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

Below are the few Sample output

Computing Value for N=3, R=2
3
1       12
2       13
3       23

Computing Value for N=4, R=2
6
1       12
2       13
3       23
4       14
5       24
6       34

Computing Value for N=4, R=3
4
1       123
2       124
3       134
4       234
*/

int64_t dp[66][33];
int64_t nCr(int n, int r)
{
    if (n == r) return dp[n][r] = 1;
    if (r == 0) 
        return dp[n][r] = 1;
    if (r == 1) return dp[n][r] = (int64_t)n;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}


vector<vector<int>> findComb(int n, int r, vector<int> inpAr)
{
    vector<vector<int>> retAr;
    if (n == r)
    {
        retAr.push_back(inpAr);
        return retAr;
    }
    if (r == 1)
    {
        for (auto&& e : inpAr)
        {
            vector<int> va; va.push_back(e);
            retAr.push_back(va);
        }
        return retAr;
    }
    if (r == 0)
    {
        // Insert an empty array
        retAr.push_back(vector<int>());
    }

    // NCR = N-1 C R-1  + N-1 C R
    int lastElem = inpAr.back();
    inpAr.pop_back();
    vector<vector<int>> arrWithoutElem = findComb(n-1, r, inpAr);
    vector<vector<int>> arrWithElem = findComb(n - 1, r-1, inpAr);

    for (auto&& e : arrWithoutElem)
    {
        retAr.push_back(e);
    }

    for (auto e : arrWithElem)
    {
        e.push_back(lastElem);
        retAr.push_back(e);
    }

    return retAr;
}


int main(int argc, char* argv[])
{
 
    cout << "Enter N and R - seperated by space" << endl;
    int n, r;
    while (scanf_s("%d %d", &n, &r) == 2)
    {
        if (r > n)
        {
            cout << "Invalid input R > N, please re-enter." << endl;
            continue;
        }
        cout << "Computing Value for N=" << n << ", R=" << r << endl;
        printf("%llu\n", nCr(n, r));

        vector<int> inp;
        for (int i = 1; i <= n; i++)
            inp.push_back(i);

        vector<vector<int>> result = findComb(n, r, inp);
        int count = 0;
        for (auto&& oA : result)
        {
            cout << ++count << '\t';
            for_each(oA.begin(), oA.end(), [](int v) { cout << v; });
            cout << endl;
        }

        cout << "Enter N and R - seperated by space" << endl;
    }

    return 1;
}
