#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int i = 1;
    int result = 0;
    while (i*i < N)
    {
        if (N%i == 0)
            result += 2;
        ++i;
    }
    if (i*i == N)
        ++result;
    return result;
}




int main(int argc, char* argv[])
{
    int n = 24;
    cout << "count_factors(" << n << ")=" << solution(n) << endl;
    return 0;
}
