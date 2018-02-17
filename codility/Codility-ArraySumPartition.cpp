

#include <climits>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> sumArr;
    int N = A.size();
    sumArr.resize(N);
    sumArr[N-1] = A[N-1];
    for (int i = N-2; i >= 0; i-- )
    {
        sumArr[i] = sumArr[i+1] + A[i];
    }
    
    //cout << "INT_MIN=" << INT_MIN <<endl;
    
    int minVal = INT_MAX;
    int lSum = A[0];
    for (int i = 1; i < N; i++ )
    {
        int cMin = abs(sumArr[i] - lSum);
        minVal = min(minVal, cMin);
        //cout << "A[i]=" << A[i] << ", sumArr[i]="<< sumArr[i] << ", cMin=" << cMin
        //<< ", minVal=" << minVal << endl;
        lSum = lSum + A[i];
    }
    
    return minVal;
}


