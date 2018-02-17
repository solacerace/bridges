#include<iostream>
#include "string.h"

using namespace std;

void swap(char& a, char& b)
{
	char t = a;
	a = b;
	b = t;
}

void reverse(char* s, int size)
{
	int li = size -1;
	int i = 0;
	while(i < li)
	{
		swap(s[i], s[li]);
		i++;
		li--;
	}
}

void reverseWord(char* s)
{
	// Reverse Each Word :
	// WHO AM I ==> OHW MA I
	int i = 0;
	int si = 0;
	int ei = 0;
	int k =0;
	while( s[i] != '\0')
	{
		// Remove spaces
		while(s[i] == ' ')
		{
			i++;
		}
		
		si = i;
		while(s[i] != ' ' && s[i] != '\0')
		{
			i++;				
		}
		ei = i-1;
		reverse(&s[si], ei-si+1);
	}
	
	// Reverse the whole string
	reverse(s, strlen(s));
}

int main(int argc, char* argv[])
{
	char str[] = "Who am i";
	
	cout << "Before=" << str << endl;
	reverseWord(str);	
	cout << "After=" << str << endl;
	return 0;
}
