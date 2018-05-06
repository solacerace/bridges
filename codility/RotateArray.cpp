#include<iostream>
#include<algorithm>

using namespace std;
void reverse(int* a, int size)
{
    int i = 0, j = size - 1;
    while (i < j) swap(a[i++], a[j--]);
}

void print(int* a, int size)
{
    for (int i = 0; i < size; ++i)
        cout << a[i] << "\t";
    cout << endl;
}

void rotate(int* a, int size, int amt)
{
    //a=12345 size=5 amt=2
    reverse(a, size); // a = 54321
    reverse(a, amt); // a = 45321
    reverse(&a[amt], size - amt); // a = 45123
}

int main(int argc, char* argv[])
{
    int a[] = { 1,2,3,4,5 };
    int size = sizeof(a) / sizeof(int);
    cout << "size=" << size << endl;
    print(a, size);
    rotate(a, size, 2);
    cout << "After rotate" << endl;
    print(a, size);
    return 0;
}


