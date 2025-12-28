class Solution {
    void dfs(int node, int currentDist, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &distArray, int &maxi)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        distArray[node] = currentDist; // Store the distance of the current node

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, currentDist + 1, adj, vis, pathVis, distArray, maxi);
            
            // If visited and currently in the path, it's a cycle
            else if (pathVis[it])
            {
                // Formula: Current Distance - Distance of the node we hit + 1
                int cycleLength = currentDist - distArray[it] + 1;
                maxi = max(maxi, cycleLength);
            }
        }
        pathVis[node] = 0;
    }

public:
    int longestCycle(vector<int>& edges) 
    {
        int V = edges.size();
        int maxi = -1; 
        
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++)
        {
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> vis(V, 0), pathVis(V, 0);
        vector<int> distArray(V, 0); // New array to track distances

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, 0, adj, vis, pathVis, distArray, maxi);
        }
        
        return maxi;
    }
};