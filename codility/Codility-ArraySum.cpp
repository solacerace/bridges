#include "stdint.h"		// C header
#include <cstdint>		// C++ header
#include <iostream>

using namespace std;

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int64_t bN = N;
    int64_t biggerSum = (bN+1)*(bN+2)/2;
    int64_t lowerSum = 0;
    for(int i = 0; i < N; i++)
    {
      lowerSum += A[i];
    }
    
    return (biggerSum-lowerSum);    
    
}


int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;	
}


