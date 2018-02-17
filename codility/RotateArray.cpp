#include<iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;	
}


void reverse(int* a, int size)
{
	for(int i = 0; i < size/2; ++i)
	{
		swap(a[i], a[size-i-1]);
	}
}

using namespace std;

void print(int* a, int size)
{
	for(int i = 0; i < size; ++i)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void rotate(int* a, int size, int amt)
{
	
	// Reverse a[0, size-amt]
	reverse(a, size-amt);
	print(a,size);
	// Reverse a[size-amt, size]
	reverse(&a[size-amt], amt);
	print(a,size);
	// Reverse array
	reverse(a, size);
	print(a,size);
}


int main(int argc, char* argv[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(a)/ sizeof(int);
	cout << "size=" <<  size << endl;
	print(a, size);
	rotate(a, size, 2);
	cout << "After rotate" << endl;
	print(a, size);
	return 0;
}


