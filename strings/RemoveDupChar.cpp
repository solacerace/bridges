
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void removeDupChar(char* str)
{
	bool foundArr[255] = {false};
	
	int len = strlen(str);
	int j = 0;
	for ( int i = 0; i < len; ++i)
	{
		if (!foundArr[str[i]])
		{
			str[j++] = str[i];
			foundArr[str[i]] = true;
		}
	}
	str[j] = '\0';
	return;
}


class ABC
{
	public:
		ABC(int x){
		}
		
	void function()
	{
	}
};

int main(int argc, char* argv[])
{
	ABC a();
	
	char inputStr[] = "Hello World";	
	
	cout << "Before=" << inputStr << endl;
	removeDupChar(inputStr);
	cout << "After=" << inputStr << endl;
	
	return 0;
}



