int dfs(int node , vector<vector<int>> &adj , vector<int> &vis)
{
    // return 1 if loop found
    vis[node] = 1;
    for (int i=0 ; i<adj[node].size() ; i++)
    {
        int val = adj[node][i];
        if (vis[val] == 1) return 1;
        if (dfs(val , adj , vis))  return 1;
    }
    vis[node] = 2;
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    int m = B.size();
    vector<vector<int>> adj(A+1 , vector<int>(0,0));
    vector<int> vis(A+1 , 0);
    for (int i=0 ; i<m ; i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    for (int i=1 ; i<=A ; i++)
    {
        if (!vis[i]) {
            if (dfs(i , adj , vis)) return 1;
        }
    }
    return 0;
}
