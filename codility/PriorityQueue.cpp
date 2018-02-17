
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int main(int argc, char* argv[])
{
	vector<int> v = {2,4,6,8,10};
	for (auto&& i : v)
	{
		cout << i << " " ;
	}
	cout << endl;
	
	
	vector<int> vi = {1,2,3,4,5};
	for_each ( vi.begin(), vi.end(), [](auto&& a){cout << a << " "; } );


	priority_queue<int> pq(vi.begin(), vi.end());
	pq.push(20);
	pq.push(10);
	
	cout << "\nTop=" << pq.top() << endl;
	pq.pop();
	cout << "\nTop=" << pq.top() << endl;
	
	
	priority_queue<int, vector<int>, greater<int>> pg(vi.begin(), vi.end());
	
	cout << "\nTop=" << pg.top() << endl;
	pg.pop();
	cout << "\nTop=" << pg.top() << endl;
	

	return 0;
}


