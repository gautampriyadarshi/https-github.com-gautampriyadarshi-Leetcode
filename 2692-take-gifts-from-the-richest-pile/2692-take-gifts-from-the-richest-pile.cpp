class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        long long ans = 0;
        int n = gifts.size()-1;
        while(k > 0)
        {
            sort(gifts.begin(), gifts.end());
            gifts[n] = sqrt(gifts[n]);
            k--;
        }

        for(int i = 0; i < gifts.size(); i++)
        {
            ans += gifts[i];
        }
        return ans;
    }
};