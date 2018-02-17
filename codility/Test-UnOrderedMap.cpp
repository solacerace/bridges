#include "stdint.h"		// C header
#include <cstdint>		// C++ header
#include <iostream>
#include <unordered_map>

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
	unordered_map<string, int> umap;
	cout << "umap.bucket_count() = " << umap.bucket_count() << endl;
	umap["Hello"] = 1;
	umap["How"] = 1;
	umap["Are"] = 1;
	umap["You"] = 1;
	
	umap.reserve(100);
	cout << "umap.bucket_count() = " << umap.bucket_count() << endl;
	cout << "umap.bucket() = " << umap.bucket("Hello") << endl;
	cout << "umap.bucket_size() = " << umap.bucket_size(7) << endl;
	cout << "umap.max_bucket_count() = " << umap.max_bucket_count() << endl;
	
	cout << "umap.load_factor() = " << umap.load_factor() << endl;
	cout << "umap.max_load_factor() = " << umap.max_load_factor() << endl;
	
	
	cout << "Hello World" << endl;	
}


