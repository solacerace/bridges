#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


void removeDup(string& s)
{
    bool found[255] = {false};
    int i = 0, j = 0, N = s.length();
    
    while (i < N)
    {
        if (found[s[i]] == false)
        {
            found[s[i]] = true;
            s[j++] = s[i];
        }
        i++;
    }

    s.erase(s.begin() + j, s.end());    
}

int main_rd()
{
    string s("geeksforgeeks");
    removeDup(s);
    cout << s << endl;
    return 0;
}



