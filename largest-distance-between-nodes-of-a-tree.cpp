int dfs (int node , int &ans , vector<vector<int>> &adj , vector<int> &vis)
{
    // cout << "value of node - " << node << "\n";
    int ans1 = 0; 
    int ans2 = 0;
    vis[node] = 1;
    for (int i=0 ; i<adj[node].size() ; i++)
    {
        
        int it = adj[node][i];
        
        int x = 0;
        // cout <<  it << " it " << vis[it] << " vis[it]\n";
        
        if (vis[it] == 1) continue;
        
        x = dfs(it , ans , adj , vis);
        
        if (x > ans1) {
            ans2 = ans1;
            ans1 = x;
        }
        else if (x > ans2) ans2 = x;
        
        // cout << "value of ans1 - " << ans1 << " ans2 - " << ans2 << "\n";
    }
    if (ans < (ans1+ans2)) ans = ans1 + ans2;
    return ans1+1;
}
int Solution::solve(vector<int> &A) {
    int ans = 0 , root = -1;
    
    int n = A.size();
    vector<vector<int>> adj(n , vector<int>(0,0));
    vector<int> vis(n , 0);
    for (int i=0 ; i<n ; i++)
    {
        if (A[i] == -1) {
            root = i;
            continue ;
        }
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    // for (int i=0 ; i<n ; i++)
    // {
    //     cout << i << " i , adj[i] - ";
    //     for (int j=0 ; j<adj[i].size() ; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "value of root - " << root << "\n";
    int x = dfs(root , ans , adj , vis);
    
    // if (ans == 0) return x-1;
    return ans;
}
