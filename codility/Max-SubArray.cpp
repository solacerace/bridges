#include<climits>	// INT_MIN, INT-MAX
#include<iostream>
#include<vector>
#include<algorithm> // min, max
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int gmin = INT_MAX;
    int maxProfit = 0;
    int N = A.size();
    for (int i = 0; i < N; ++i)
    {
    	// Find the minimum element
        gmin = min(gmin, A[i]);
        
        // Find the max difference upto now
        maxProfit = max(maxProfit,A[i] - gmin);
    }
    
    return maxProfit;
}

// https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/
// This solution has resulted in 100% accuracy
int maxSubArray(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int maxEndingHere, maxSubArray;
    maxEndingHere = maxSubArray = A[0];
    int N = A.size();
    for (int i = 1; i < N; ++i)
    {
    	// Find the minimum element
        maxEndingHere = max(A[i], maxEndingHere+A[i]);
        
        // Find the max difference upto now
        maxSubArray = max(maxSubArray,maxEndingHere);
    }
    
    return maxSubArray;
}


int main(int argc, char* argv[])
{
	//int arr[] = {2,3,-1,4};
	vector<int> v={2,3,-9,4};
	
	cout << "Solution=" << solution(v) << endl;
	cout << "Solution=" << maxSubArray(v) << endl;
		
	return 0;
}




