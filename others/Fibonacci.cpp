#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
unordered_map<int, int> umap;

int fibonacci_num(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (umap.find(n) == umap.end())
    {
        int val = fibonacci_num(n - 1) + fibonacci_num(n - 2);
        umap.insert(make_pair(n, val));
        return val;
    }
    else
        return umap[n];
}

int main(int argc, char* argv[])
{
    int n = 20;
    cout << "fibo("<< n <<")=" << fibonacci_num(n) << endl;
    return 0;
}
