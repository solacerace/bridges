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

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if (N < 3)
        return 0;
    // Find all the peaks
    vector<int> peaks;
    for(int i = 1; i < N-1; i++){
      if(A[i] > A[i-1] && A[i] > A[i+1]) peaks.push_back(i);
    }

    for(int size = 1; size <= N; size++){
      if(N % size != 0) continue; // skip if non-divisible
      int find = 0;
      int groups = N/size;
      bool ok = true;
      // Find whether every group has a peak
      for(int peakIdx : peaks){
        //cout << "peaks.size()=" << peaks.size() << endl;
        if(peakIdx/size > find){
          ok = false;
          break;
        }
        if(peakIdx/size == find) find++;
      }
      if(find != groups) ok = false;
      if(ok) 
      {
          //cout << "find="<<find<<", groups="<<groups<<", size="<<size <<endl;
          return groups;
      }
    }
    return 0;    
}




int main(int argc, char* argv[])
{
	int a[] = {1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution(va);
	
	cout << "Result=" << res << endl;	
}





