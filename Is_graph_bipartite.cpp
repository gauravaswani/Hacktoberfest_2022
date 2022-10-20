/*

There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:

- There are no self-edges (`graph[u]` does not contain `u`).
- There are no parallel edges (`graph[u]` does not contain duplicate values).
- If `v` is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).
- The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` *if and only if it is **bipartite***.

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

*/
class Solution 
{
private:
    map<int,vector<int>> adjlist;
    vector<int> color; //0-->white, 1-->red, 2-->blue
    vector<bool> visited;
    bool is_bipartite=true;
    void color_graph(int u,int cur_color)
    {
        if(color[u]!=0 && color[u]!=cur_color)
        {
            is_bipartite=false;
            return;
        }
        color[u]=cur_color;
        if(visited[u]==true)
        {
            return;
        }
        visited[u]=true;
        
        for(auto i:adjlist[u])
        {
            if(cur_color==1)
            {
                color_graph(i,2);
            }
            else
            {
                color_graph(i,1);
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        
        color.resize(n,0);
        visited.resize(n,false);
        
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                adjlist[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                color_graph(i,1);
            }
        }
        return is_bipartite;
    }
};