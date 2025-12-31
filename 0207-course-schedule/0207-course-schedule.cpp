class Solution {
    bool dfs(int node, stack<int> &st, vector<int> &vis, vector<int> &pathVis,
    vector<vector<int>> &adj)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, st, vis, pathVis, adj))
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
        st.push(node);
        pathVis[node] = 0;

        return false;
    }
public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    bool canFinish(int V, vector<vector<int>>& edges) 
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);  // Additional added
        vector<vector<int>> adj(V);

        for(int i = 0; i < edges.size(); i++)
        {
            // adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        stack<int> st;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, st, vis, pathVis, adj))    // If cycle exists then returing {}.
                    return false;
            }
        }
        return true;
    }
};