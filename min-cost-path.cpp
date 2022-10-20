int Solution::solve(int n, int m, vector<string> &C) {
    vector<vector<int>> vis(n , vector<int>(m, INT_MAX));
    deque<pair<int,int>> q;
    q.push_front({0,0});
    vis[0][0] = 0;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop_front();
        int x = p.first , y = p.second;
        // cout << x << " x,y " << y << "\n";
        

        if (x-1>-1) {
            int val = vis[x][y];
            if (C[x][y]=='U')
            {
                if (val < vis[x-1][y]) {
                    vis[x-1][y] = val;
                    q.push_front({x-1,y});
                }
            }
            else 
            {
                if (val+1 < vis[x-1][y]) {
                    vis[x-1][y] = val+1;
                    q.push_back({x-1 , y});
                }    
            }
        }
        if (x+1<n) {
            int val = vis[x][y];
            if (C[x][y]=='D')
            {
                if (val < vis[x+1][y]) {
                    vis[x+1][y] = val;
                    q.push_front({x+1,y});
                }
            }
            else 
            {
                if (val+1 < vis[x+1][y]) {
                    vis[x+1][y] = val+1;
                    q.push_back({x+1 , y});
                }    
            }
        }
        if (y-1>-1)
        {
            int val = vis[x][y];
            if (C[x][y]=='L')
            {
                if (val < vis[x][y-1]) {
                    vis[x][y-1] = val;
                    q.push_front({x,y-1});
                }
            }
            else 
            {
                if (val+1 < vis[x][y-1]) {
                    vis[x][y-1] = val+1;
                    q.push_back({x , y-1});
                }    
            }
        }
        if (y+1<m)
        {
            int val = vis[x][y];
            if (C[x][y]=='R')
            {
                if (val < vis[x][y+1]) {
                    vis[x][y+1] = val;
                    q.push_front({x,y+1});
                }
            }
            else 
            {
                if (val+1 < vis[x][y+1]) {
                    vis[x][y+1] = val+1;
                    q.push_back({x , y+1});
                }    
            }
        }
    }
    return vis[n-1][m-1];
}
