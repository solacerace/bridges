#include<iostream>
#include<unordered_set>
#include "string.h"

using namespace std;

void revVowel(char* s)
{
	unordered_set<char> us = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	int N = strlen(s);
	int j = N-1, i = 0;
	while(i < j)
	{
		// Find left vowel
		while(i<j && us.find(s[i]) == us.end()) i++;
		
		// find right vowel
		while(i<j && us.find(s[j]) == us.end()) j--;
			
		if (i < j) swap(s[i++], s[j--]);
	}
	
}

int main(int argc, char* argv[])
{
	char s[] = "HERO";
	cout << s << endl;
	revVowel(s);
	cout << s << endl;
	return 0;
}

