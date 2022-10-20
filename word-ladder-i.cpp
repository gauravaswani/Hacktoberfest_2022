int check(string A, string B)
{
    int cnt = 0;
    for (int i=0 ; i<A.length() ; i++)
    {
        if (A[i]!=B[i]) {
            if (cnt == 1) return 0;
            cnt = 1;
        }
    }
    return 1;
}
int Solution::solve(string A, string B, vector<string> &C) 
{

    unordered_set<string> s; // all strings stored in set

    for (int i=0 ; i<C.size() ; i++) {
        s.insert(C[i]);
    }

    
    
    queue<string> q;
    q.push(A);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        level ++;
        while (sz>0)
        {
            string str = q.front(); q.pop();
            
            if (str == B) return level;
            
            for (int i=0 ; i<str.length() ; i++)
            {
                string temp = str;
                char value = temp[i];
                for (int j=0 ; j<26 ; j++)
                {
                    if (j == value-'a') continue;
                    temp[i] = 'a' + j;
                    if (temp == B) return level+1;
                    
                    if (s.find(temp) != s.end()) 
                    {
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }

            sz--;
        }
        // check all possible values from str
        // int val = q.front(); q.pop();
        // if (val == n-1) break;
        // // cout << "front val- " << val << "\n";
        // int x = vis[val] + 1;
        // for (int i=0 ; i<n ; i++)
        // {
        //     if (val!=i && check(arr[val],arr[i]) && vis[i]>x) {
        //         vis[i] = x;
        //         q.push(i);
        //     }
        // }
    }
    return 0;    
}
