int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // Allocate bool array of size A.size()
    vector<bool> vb(A.size()+1, false);
    int N = A.size();
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 1 || A[i] > N)
        {
            return 0;
        }
        else
        {
            vb[A[i]] = true;
        }
    }
    
    for (int i = 1; i < N+1; i++)
    {
        if (vb[i] == false)
        {
            return 0;
        }
    }
    
    return 1;
}



