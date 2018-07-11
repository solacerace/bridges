#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


void removeExtraSpace2(char* s)
{
    int i = 0, j = 0, N = strlen(s);
    bool prevSpace = false;

    while (i < N && s[i] == ' ')
        i++;
    for (; i < N; i++)
    {
        if (s[i] != ' ')
        {
            s[j++] = s[i];
        }            
        else if (s[i] == ' ')
        {
            if (!prevSpace)
            {
                s[j++] = s[i];
                prevSpace = true;
            }
        }
    }
}

void removeExtraSpace(char* s)
{
    int j = 0, i =0, N=strlen(s);
    // Remove initial spaces
    while (i < N && s[i] == ' ')
    {
        i++;
    }

    while (i < N )
    {
        while (i < N && s[i] != ' ')
            s[j++] = s[i++];

        while(i < N-1 && s[i] == ' ' && s[i+1] == ' ')
        i++;

        if (i < N && s[i] == ' ')
            s[j++] = s[i++];
    }

    if (s[j - 1] == ' ')
        s[j - 1] = '\0';
    else
        s[j] = '\0';
}

int main_res()
{
    char s[100]= "  HELLO HOW    ARE     ";
    cout << "in=" << s << endl;
    removeExtraSpace(s);
    cout << "out=" << s << strlen(s) << endl;
    return 0;
}



