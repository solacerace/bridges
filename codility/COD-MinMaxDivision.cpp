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


int sum(vector<int> a) 
{ 
	int sum = 0; 
	for(int i =0; i < a.size(); ++i) 
	{ 
		sum+=a[i]; 
	} 
	return sum; 	
}

int max(vector<int> a) 
{ 
	int max = -1; 
	for(int i =0; i < a.size(); ++i) 
	{ 
		if (a[i] > max)
		{
			max = a[i];
		}			
	} 
	return max; 	
}

int calculateBlockCount(vector<int> a, int maxSum) 
{
	int count = 0;
	int sum = a[0];
	for(int i=1; i<a.size(); i++)
	{
		if(sum + a[i] > maxSum){
			count++;
			sum = a[i];
		}else{
			sum += a[i];
		}
	}
	return count;
}


int solution(int K, int M, vector<int>& A) {
	int lower = max(A);
	int upper = sum(A);
	
	
	while(true){
		int mid = (lower+upper)/2;
		cout << "lower="<< lower << ", upper=" << upper << ", mid="<<mid << endl; 
		int blocks = calculateBlockCount(A, mid);
		cout << "mid="<< mid << ", blocks=" << blocks << endl; 
		if(blocks < K){
			upper = mid-1;
		}else if(blocks > K){
			lower = mid+1;
		}else{
			return upper;
		}
	}
}


int main(int argc, char* argv[])
{
	//int a[] = {2, 1, 5, 1, 2, 2, 2};
	int a[] = {1, 1, 1, 1, 1, 1, 2};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(3, 5, va);
	
	cout << "Result=" << res << endl;
	return 0;
}





