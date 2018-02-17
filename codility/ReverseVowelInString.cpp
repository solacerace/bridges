#include<iostream>
#include<unordered_set>
#include "string.h"

using namespace std;

void revVowel(char* s)
{
	unordered_set<char> us = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	int N = strlen(s);
	int j = N-1;
	int i = 0, k =0;
	while(i < j)
	{
		cout << ++k << endl;
		// Find left vowel
		while(i<j && us.find(s[i]) == us.end())
			i++;
		
		cout << ++k << endl;
		
		// find right vowel
		while(i<j && us.find(s[j]) == us.end())
			j--;
			
		cout << ++k << endl;	
		if (i < j)
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}
		
	}
	
}

int main(int argc, char* argv[])
{
	char s[] = "HLL";
	cout << s << endl;
	revVowel(s);
	cout << s << endl;
	return 0;
}

