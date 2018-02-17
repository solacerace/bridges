#include<iostream>

using namespace std;

int stringToInt(char* s)
{
	int i =0, num = 0;
	
	while(s[i] != '\0')
	{
		num = num*10;
		num = num + (s[i] - '0');		
		i++;
	}
	return num;
}

int main(int argc, char* argv[])
{
	char s[] = "12345";
	
	int num = stringToInt(s);
	
	cout << "Val=" << num << endl;
	
	return 0;
}
