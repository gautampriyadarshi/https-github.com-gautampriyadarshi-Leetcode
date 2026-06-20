/************ 
Time Complexity: O(E*T * log(E*T))

Graph Construction: Building the adjacency list takes O(E) time.

Priority Queue (Dijkstra): * In standard Dijkstra, a node is processed exactly once. However, because we have two constraints (cost and time), we might visit the same node multiple times if a more expensive path gets us there faster.

Because of the condition newTime < minTime [adjNode], we only push a node to the queue if it strictly improves the arrival time. Since time is an integer and capped at T, a single node can be pushed into the priority queue at most T times.

This means we can traverse each of the E edges at most T times. Therefore, the maximum number of push operations to the priority queue is ET.

The priority queue will hold at most E T elements. Pushing or popping from a heap of this size takes O(log(ET)) time. ************/

/********** 
Space Complexity: O(V + E*T)
Adjacency List: Storing the graph takes O(V + E) space.
Tracking Array: The minTime vector takes O(V) space.

Priority Queue: In the absolute worst-case scenario, if many paths are explored that continually improve the time marginally, the priority queue could store up to E T elements at once. Each element is a vector of size 3, which takes O(ET) space.

Combining these, the dominant term for space in the worst case is the priority queue, leaving us with an overall space complexity of O(V + E-T). *********/

// Time Complexity: O(E*T * log(E*T))
// Space Complexity: O(V + E*T)
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