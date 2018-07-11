#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;










int solution(string &s) {
    // write your code in C++14 (g++ 6.2.0)

    std::string operation;                 // Have a buffer string
    std::stringstream ss(s);       // Insert the string into a stream
    stack<int> st;
    int MAX = pow(2, 20) - 1;
    //cout << "MAX = " << MAX << endl;
    while (ss >> operation)
    {
        if (operation == "DUP")
        {
            //cout << "DUP" << "--" << operation << endl;
            if (st.size() < 1)
                return -1;
            st.push(st.top());
        }
        else if (operation == "POP")
        {
            //cout << "POP" << "--" << operation << endl;
            if (st.size() < 1)
                return -1;
            st.pop();
        }
        else if (operation == "+")
        {
            //cout << "+" << "--" << operation << endl;
            if (st.size() < 2)
                return -1;
            
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int sum = first + second;
            
            if (sum > MAX)
                return -1;
            
            st.push(sum);
        }
        else if (operation == "-")
        {
            //cout << "-" << "--" << operation << endl;
            if (st.size() < 2)
                return -1;

            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            int diff = first - second;

            if (diff < 0)
                return -1;

            st.push(diff);            
        }
        else


        {
            int val = std::stoi(operation);
            //int val = atoi(operation.c_str());
            // If val > 
            if (val > MAX || val < 0)
                return -1;
            st.push(val);            
        }
    }

    if (st.size() < 1)
        return -1;

    return st.top();
}

void print(const string& s)
{
    string scopy(s);
    cout << "Input=" << s << endl;
    int result = solution(scopy);
    cout << "result = " << result << endl;
}

int main(int argc, char* argv[])
{
    
    print(string("    "));

    print(string("13 DUP 4 POP 5 DUP + DUP + -"));
    print(string("5 6 + -"));
    print(string("3 DUP 5 - -"));
    print(string("+ -"));
    print(string("-"));
    print(string("13 +"));
    print(string("13 DUP +"));
    print(string("13 DUP + POP")); //
    print(string("13 DUP + 20"));
    print(string("13 DUP + 20 -"));
    print(string("13 DUP + 26 -"));
    print(string("13 DUP + 27 -"));
    print(string("13 DUP + 24 -"));

    print(string("13 DUP + 24 + 1048575"));
    print(string("13 DUP + 24 + 1048575 +"));
    print(string("1048575 1 +"));
    print(string("1048575 0 +"));
    print(string(""));
    print(string(" "));
    print(string("1234"));
    print(string("0"));
    print(string("-10"));
    print(string("3 3 2 DUP POP + -"));


    return 0;
}

