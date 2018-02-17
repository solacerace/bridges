
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<set>
#include<vector>
using namespace std;

int solution(int H[], int N) {
    // write your code in C99
    int stones=0;
    stack<int> s;

    
    for (int i=0;i<N;i++) 
	{ 
        while ( (!s.empty()) && (s.top() > H[i]) )
            s.pop();
        //if (!(!s.empty() && s.top() == H[i]))
        if (s.empty() || s.top() != H[i] )
		{
        	// We enter here if stack is empty or stack.top() < H[i]
            stones +=1;
            s.push(H[i]);            
        }
    }
    
    return stones;
    
}


int main(int argc, char* argv[])
{
	
	using namespace std;
	int arr[] = {1,2,3,2,1,3};
	//vector<int> va(arr, arr + sizeof(arr)/sizeof(arr[0]));
	int res = solution(arr, sizeof(arr)/sizeof(arr[0]));
	
	cout << "The result=" << res << endl;
	
	return 0;	
}


