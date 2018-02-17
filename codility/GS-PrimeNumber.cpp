#include<iostream>
#include<vector>
#include<math.h>
#include<set>
#include<algorithm>

using namespace std;



// A function to print all prime factors of a given number n
vector<int> primeFactors(int n)
{
	vector<int> vec;
	// Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);        
        vec.push_back(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            vec.push_back(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
    {
        printf ("%d ", n);
        vec.push_back(n);    
	}
        
    return vec;
}

bool primeFactorhelper(int x, vector<int>& exp)
{
	vector<int> res = primeFactors(x);
	sort(res.begin(), res.end());
	return (exp == res);	
}

int main(int argc, char* argv[])
{
	cout << "Hello World" << endl;
	
	bool result = true;
	result = result && primeFactorhelper(12, vector<int>()={2,2,3});
	result = result && primeFactorhelper(6, vector<int>()={2,3});
	
	if (result)
	{
		cout << " PASS " << endl;
	}
	else
	{
		cout << " FAIL " << endl;
	}
		
	return 0;
}
