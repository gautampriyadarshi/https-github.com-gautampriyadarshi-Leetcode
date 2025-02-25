class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto i: mp)
        {
            pq.push(make_pair(i.second, i.first));
        }

        for(int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};