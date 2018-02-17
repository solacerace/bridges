#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;
char solution(string& S) 
{
	int occurrences[26];
	for (int i =0; i < 26; ++i)
	{
		occurrences[i] = 0;
	}
	
	for (char ch: S)
	{
		occurrences[ch -'a']++;
	}
	
	char best_char = 'a';
	int best_res = occurrences[0];
	
	for (int i = 1; i < 26; ++i)
	{
		if (occurrences[i] > best_res)
		{
			best_char = 'a' + i;
			best_res = occurrences[i];
		}
	}
	
    
    return best_char;
    
}


int main(int argc, char* argv[])
{

	string str = "abcdddddaaa";	
	char res = solution(str);
	
	cout << "Result=" << res << endl;	
}


