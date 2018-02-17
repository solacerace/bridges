#include<iostream>
#include "string.h"

using namespace std;

int longSeq(char* s)
{
	int N = strlen(s);
	
	if (N == 1)
		return 1;
		
	char prev = s[0];
	int count = 1;
	int m = 1;
	for (int i = 1; i < N; ++i)
	{
		char c = s[i];
		
		if (prev == c)
		{
			count++;
		}
		else
		{
			m = (m>count)?m:count;
			count = 1;
			prev = c;
		}
	}
	m = (m>count)?m:count;
	return m;
}

int main(int argc, char* argv[])
{
	char s[] = "aaabccd";
	
	int max = longSeq(s);
	
	cout << "max = " << max << endl;
	
	return 0;
}


