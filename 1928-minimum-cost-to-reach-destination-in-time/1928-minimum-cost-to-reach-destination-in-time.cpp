class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) 
    {
        int n = passingFees.size(); 
        vector<pair<int, int>> adj[n];
        
        for (int i = 0; i < edges.size(); i++)
        {
            int u  = edges[i][0];
            int v  = edges[i][1];
            int wt = edges[i][2]; // Note: This weight represents TIME

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Track the minimum TIME taken to reach each node so far
        vector<int> minTime(n, INT_MAX); 
        
        // Start at node 0: {initial cost, time taken, starting node}
        pq.push({passingFees[0], 0, 0}); 
        minTime[0] = 0;
        
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int cost = it[0];
            int time = it[1];
            int node = it[2];
            
            // Because we pop by minimum cost, the first time we hit the destination, 
            // it is guaranteed to be the cheapest valid path!
            if (node == n - 1) {
                return cost;
            }
            
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgW = it.second; // time taken for this road
                
                int newTime = time + edgW;
                int newCost = cost + passingFees[adjNode];
                
                // Only process this path if it strictly improves our time to this node
                // AND stays within our maxTime limit
                if (newTime <= maxTime && newTime < minTime[adjNode])
                {
                    minTime[adjNode] = newTime;
                    pq.push({newCost, newTime, adjNode});
                }
            }
        }
        
        return -1; // Cannot reach destination within maxTime
    }
};