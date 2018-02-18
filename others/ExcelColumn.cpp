#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>



using namespace std;



string excelColumn(int x)
{
    if (x > 0)
    {
        int rem = x%26;
        
        char c[2] = {};
        if (rem == 0)
        {
            c[0] = 'Z';
            x = x/26 - 1;
        }
        else
        {
            c[0] = 'A' + rem-1;
            x = x/26;			
        }
        
        return excelColumn(x) + c;
    }
    
    return "";

}


int main(int argc, char* argv[])
{
    vector<int> v = {2,4,6,8,10};
    for (auto&& i : v)
    {
        cout << i << " " ;
    }
    cout << endl;
    
    
    cout << excelColumn(26) << endl;
    cout << excelColumn(51) << endl;
    cout << excelColumn(52) << endl;
    cout << excelColumn(80) << endl;
    cout << excelColumn(676) << endl;
    cout << excelColumn(702) << endl;
    cout << excelColumn(705) << endl;
    

    return 0;
}


