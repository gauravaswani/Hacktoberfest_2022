int dfs(int node , vector<vector<int>> &adj , vector<int> &vis)
{
    vis[node] = 1;
    // cout << node << " value of node\n";
    for (auto itr : adj[node])
    {
        if (!vis[itr]) {
            dfs(itr , adj , vis);
        }
    }
    return 1;
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {
    set<pair<int,int>> s;
    vector<vector<int>> adj(A+1 , vector<int>(0,0));
    vector<int> vis(A+1 , 0);
    for (int i=0 ; i<B.size() ; i++)
    {
        if (B[i][0] == B[i][1]) continue;
        s.insert({B[i][0] , B[i][1]});
    }
    for (auto itr : s)
    {
        adj[itr.first].push_back(itr.second);
    }
    int node = -1;
    for (int i=1 ; i<A+1 ; i++)
    {
        if (!vis[i]) {
            // run dfs
            dfs(i,adj,vis);
            node = i;
        }
    }
    if (node == -1) return 0;
    // check if all nodes are covered by 'node' in dfs
    for (int i=0 ; i<A+1 ; i++) vis[i] = 0;
    dfs(node , adj , vis);
    for (int i=1 ; i<A+1 ; i++)
    {
        if (vis[i] == 0) return 0;
    }
    return 1;
}
