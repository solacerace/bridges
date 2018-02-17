#include<iostream>
#include "string.h"

using namespace std;
int lengthofLWord(char* s)
{
	int i = 0;
	int N = strlen(s);
	int li = N-1;
	// find last word
	// Remove trailing spaces
	while(li != -1 && s[li] == ' ' )
	li--;
	
	if (li == -1)
		return 0;
	
	int last = li;
	// Remove alphabets
	while(s[li] != ' ' && li != -1)
	li--;
	li++;
	int start = li;
	
	return (last - start+1);
}

int main(int argc, char* argv[])
{
	char s[] = "Hello";
	
	cout << lengthofLWord(s) << endl;
	
	return 0;
}
