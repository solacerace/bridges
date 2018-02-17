#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <climits>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

/*
int solution1(vector<int>& A) {

// use the fast row to sort first
  int ans = 0;
  if (A.size() == 2) 
  return A[1] - A[0];
  for (int i=1; i < A.size() - 1; i++) {
    if (A[i]-A[i-1] > ans) {
        ans = A[i]-A[i-1];
    }
  }
  return ans;
}
*/

int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
		
}

int solution1(vector<int>& A) {
	sort(A.begin(), A.end());
        int dist = INT_MIN;
    if (A.size() == 2) return (A[1] - A[0]) / 2;
    for (int i=0; i < A.size() - 1; i++) {
// if there is a free position between two points

        if (A[i+1] - A[i] > 1) {
            dist = max(dist, A[i+1] - A[i]);
        }
    }
         
    return dist / 2;
}



int main(int argc, char* argv[])
{
	int a[] = {5,5};
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	
	int res = solution1(va);
	
	cout << "Result=" << res << endl;	
}





