
int check(vector<vector<int>>& adj , vector<bool> &s , int index , int &A) 
{
    if (index == A-1) return 1;    
    if (s[index] == true) return 0;
    s[index] = true;
    
    int n = adj[index].size();
    if (n == 0) return 0;
    
    for (int x=0 ; x<n ; x++)
    {
        int i = adj[index][x];

        if (i == A) return 1;

        if (s[i-1]==false && check(adj , s , i-1 , A) == 1) return 1;
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    int m = B.size();
    vector<vector<int>> adj(A,vector<int>(0,0));
    for (int i=0 ; i<m ; i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]);
    }
    
    // check if path exists from node 1 to node A
    vector<bool> s(A , false);
    
    return check(adj , s , 0 , A);
}
