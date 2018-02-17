

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[])
{
	vector<int> v = {2,4,6,8,10};
	for (auto&& i : v)
	{
		cout << i << " " ;
	}
	cout << endl;
	
	
	// Copy Elements
	int a[v.size()];
	copy(v.begin(), v.end(), a);
	for (auto&& i : a)
	{
		cout << i << " " ;
	}
	cout << endl;
	
	vector<int> vi = {1,2,3,4,5};
	for_each ( vi.begin(), vi.end(), [](auto&& a){cout << a << " "; } );


	return 0;
}


