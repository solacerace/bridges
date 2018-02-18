/*
Given an input string and a dictionary of words, 
Print All combination of words formed by the input 
string from dictionary of words.

input = "loveisnowhere"
output= [love is no where
		 love is now here]
*/
#include<iostream>
#include<limits>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include "conio.h"
#include <functional>

using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
An array of strings is used for dictionary.  Using array of strings for
dictionary is definitely not a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string word)
{
	string dictionary[] = { "love","is","no","now","here","where"};
	int size = sizeof(dictionary) / sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

void wordBreakUtil(string str, int n, string result)
{
    for (int i = 1; i <= n; i++)
    {
        string prefix = str.substr(0, i);
        if (dictionaryContains(prefix))
        {
            if (i == n)
            {
                result += prefix;
                cout << "result=" << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i, result + prefix + " ");
        }
    }
}

void wordBreak(string str)
{
	wordBreakUtil(str, str.size(), "");
}

int main(int argc, char* argv[])
{
    string words = "loveisnowhere";
    cout << "Input=" << words << endl;
    wordBreak(words);
	return 0;
}