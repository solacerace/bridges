#include<iostream>
#include<limits>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include "conio.h"
#include <functional>

using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}


string justify(vector<string>& words, int M) {

    int N = words.size();
    int** cost = new int*[N];
    for (int i = 0; i < N; ++i)
        cost[i] = new int[N];
    

    //next 2 for loop is used to calculate cost of putting words from
    //i to j in one line. If words don't fit in one line then we put
    //Integer.MAX_VALUE there.
    for (int i = 0; i < N; i++) {
        cost[i][i] = M - words[i].length();
        for (int j = i + 1; j < N; j++) {
            cost[i][j] = cost[i][j - 1] - words[j].size() - 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (cost[i][j] < 0) {
                cost[i][j] = INT_MAX;
            }
            else {
                cost[i][j] *= cost[i][j];
            }
        }
    }

    /*
    * The equation is 
    *  mc[n-1] = cost[n-1][n-1]
    *  mc[i]  = min { cost[i][j-1] + mc[j] }
    *           i < j < n    
    */
    //minCost from i to len is found by trying
    //j between i to len and checking which
    //one has min value
    int* mc = new int[N];
    int* res = new int[N];
    for (int i = N - 1; i >= 0; i--) {
        mc[i] = cost[i][N - 1];
        res[i] = N;
        for (int j = N - 1; j > i; j--) {
            if (cost[i][j - 1] == INT_MAX) {
                continue;
            }
            if (mc[i] > mc[j] + cost[i][j - 1]) {
                mc[i] = mc[j] + cost[i][j - 1];
                res[i] = j;
            }
        }
    }
    int i = 0;
    int j;

    cout << "Minimum cost is " << mc[0] << endl;
    
    //finally put all words with new line added in 
    //string buffer and print it.
    string out;
    do {
        j = res[i];
        for (int k = i; k < j; k++) {
            out += words[k] + " ";			
        }
        out += "\n";
        i = j;
    } while (j < N);

    return out;
}


int main(int argc, char* argv[])
{	
    vector<string> words = { "Deepak","likes","to","write","code","at", "free", "time" };
    cout << "input=" << endl;
    for_each(words.begin(), words.end(), [](auto&& a) {cout << a << " "; });
    cout << endl;
    cout<< "Output=" << endl << justify(words, 12);

    return 0;
}
