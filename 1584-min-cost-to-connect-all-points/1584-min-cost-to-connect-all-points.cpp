class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        // adj[i]: {neighbor_index, manhattan_distance}
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int weight = abs(points[i][0] - points[j][0]) + 
                                abs(points[i][1] - points[j][1]);
                
                adj[i].push_back({j, weight});
                adj[j].push_back({i, weight});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});    // {wt, node}
        
        int sum = 0;
        vector<int> vis(n, 0);

        while(!pq.empty())
        {
            int wt   = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node])
                continue;

            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node])
            {
                int adjNode = it.first;    // From adjacency list
                int wei = it.second;

                if(!vis[adjNode])
                    pq.push({wei, adjNode});
            }
        }
        return sum;
    }
};