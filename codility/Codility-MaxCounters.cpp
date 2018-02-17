vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> rv(N, 0);
    int M = A.size();
    int lastMax = 0, gMax = 0;
    for ( int i = 0; i < M; ++i)
    {
        int c = A[i] -1;
        if (c == N)
        {
            lastMax = gMax;
        }
        else
        {
            rv[c] = max(rv[c], lastMax) + 1;
            gMax = max(rv[c], gMax);
        }
    }
    
    for ( int j = 0; j < N; ++j)
    {
        if (rv[j] < lastMax ) 
            rv[j] = lastMax;
    }
    
    return rv;    
}
