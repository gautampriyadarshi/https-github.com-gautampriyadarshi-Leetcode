#define MOD 1000000007;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // FIX 1: Initialize with LLONG_MAX instead of INT_MAX
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);     // This part was added

        dist[0] = 0;
        ways[0] = 1;                // This part was added

        // FIX 2: Change priority queue to pair<long long, int>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis > dist[node])  
                continue;

            for(auto it : adj[node])
            {
                int neighbour = it.first;
                long long wt = it.second;

                if(wt + dis < dist[neighbour])
                {
                    dist[neighbour] = wt + dis;
                    pq.push({wt + dis, neighbour});
                    ways[neighbour] = ways[node];    // This part was added
                }
                else if(wt + dis == dist[neighbour]) // This part was added
                    ways[neighbour]=(ways[neighbour] + ways[node]) % MOD;
            }
        }
        return ways[n-1] % MOD;
    }
};