#include <iostream>
#include <vector>
// you can use includes, for example:
// #include <algorithm>
#include <climits>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A, vector<int> &B) 
{
    int count = 0;
    stack<int> previousFishes;
    int N = A.size();
    for (int i = 0; i < N; i++) 
	{
        int currentFish = A[i];
        int currentFlow = B[i];
        
        // Make a note of fish going down
        if (currentFlow == 1) {
            previousFishes.push(currentFish);
        }
        
        // If fish going up and there are fishes going down, check what will be eaten
        if (!previousFishes.empty() && currentFlow == 0) 
		{
            while (!previousFishes.empty() && currentFish > previousFishes.top()) {
                previousFishes.pop();
            }
        }
        
        // If fish going up and no previous fishes going down, then increase the count
        if (previousFishes.empty() && currentFlow == 0) {
            count++;
        }
    }
    return count + previousFishes.size();	
}


  
int main(int argc, char* argv[])
{ 
	int a[] = {4, 3, 2, 1, 5};
	int b[] = {0, 1, 0, 0, 0};
	
	vector<int> va(a, a + sizeof(a)/sizeof(a[0]));
	vector<int> vb(b, b + sizeof(b)/sizeof(b[0]));
	
	int res = solution(va, vb);
	
	cout << "Result=" << res << endl;	
}





