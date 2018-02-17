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

#define glue(a,b) #a#b

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    
    return 0;
    
}



class A
{
public:
void print() {cout<<"A::print()";}
};

class B : private A
{
public:
void print() {cout<<"B::print()";}
};

class C : public B
{
public:
	
void print() {A::print();}
};
int main()
{
C b;
b.print();
return 0;
}

/*

int main(int argc, char* argv[])
{
	
	size_t sz = 0;
	
	int i = 4;
	switch(i)
	{
		default:
			;
		case 3:
			i+=5;
			if (i==8)
			{
				i++;
				if (i ==9) break;
				i*=2;				
			}
			i -= 4;
			break;
			case 8:
				i+=5;
				break;
	}
	
	printf("i=%d\n", i);
	
	return 0;
	

	cout << "sz=" << sz << endl;
	--sz;
	cout << "sz=" << sz << endl;
	
	char* wholenum = "halfnum";
	cout << glue(whole,num);
	
	return 0;
	
	
	int a[] = {2147483646};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}




*/
