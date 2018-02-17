#include<iostream>
#include<limits>
#include<algorithm>
#include "conio.h"

using namespace std;

int cutRod(int* p, int n)
{
    int r[n+1];
    r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            q = max(q, p[j] + r[i-j-1]);
        }
        r[i] = q;
    }
    return r[n];
}

int main(int argc, char* argv[])
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout<< "Maximum Value ="<< cutRod(arr, size);    
    getch();
    return 0;
}
