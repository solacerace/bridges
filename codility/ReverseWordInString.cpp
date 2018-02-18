#include<iostream>
#include<algorithm>
#include "string.h"

using namespace std;


void reverse(char* s, int size)
{
    if (size == 0) return;
    int i=0, j = size -1;	
    while(i < j)
        swap(s[i++], s[j--]);
}

void reverseWord(char* s)
{
    int i = 0, N = strlen(s);
    reverse(s,N);
    while (i < N)
    {
        int j = i;
        while (s[j] != ' ' && s[j] != '\0')
            j++;
        reverse(&s[i], j - i);
        i = ++j; // Get past the space
    }
}

int main(int argc, char* argv[])
{
    char str[] = "Who am i";	
    cout << "Before=" << str << endl;
    reverseWord(str);	
    cout << "After=" << str << endl;
    return 0;
}
