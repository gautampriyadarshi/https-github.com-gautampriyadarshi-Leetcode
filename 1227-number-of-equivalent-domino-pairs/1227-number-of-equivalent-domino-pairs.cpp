class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        map<pair<int,int>, int> mp;
        for(auto d: dominoes)
        {
            if(d[0]>d[1])
                swap(d[0], d[1]);
            
            mp[{d[0], d[1]}]++;
        }
        
        int count = 0;
        for(auto x: mp)
        {
            count += x.second * (x.second - 1)/2;
        }
        return count;
    }
};