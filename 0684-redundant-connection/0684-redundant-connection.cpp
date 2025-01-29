class Solution {
    bool Cycle(vector<vector<int>> adjList, int sr, int n)
    {
        queue<pair<int,int>> q;
        vector<bool> vis(n+1, false);

        q.push({sr,-1});
        vis[sr] = true;

        while(!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();

            for(auto x: adjList[node])
            {
                if(!vis[x])
                {
                    vis[x] = true;
                    q.push({x,node});
                }
                else
                {
                    if(x != parent)
                        return true;
                }
            }
        }
        return false;;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<vector<int>> adjList(n+1);

        for(auto x: edges)
        {
            int sr = x[0], des = x[1];
            adjList[sr].push_back(des);
            adjList[des].push_back(sr);

            if(Cycle(adjList, sr, n))
                return x;
        }
        return {};
    }
};