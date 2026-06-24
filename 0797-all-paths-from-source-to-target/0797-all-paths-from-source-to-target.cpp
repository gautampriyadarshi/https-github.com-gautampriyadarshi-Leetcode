class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &vis, vector<int> &path, int node,
             vector<vector<int>>& graph) 
    {
        path.push_back(node);
        if(node == graph.size()-1)  // last node reached
        {
            ans.push_back(path);
            return;
        }

        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                dfs(vis, path, it, graph);
                vis[it] = 0;        // Backtracking
                path.pop_back();    // Backtracking
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> path;
        dfs(vis, path, 0, graph);
        return ans;
    }
};