class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int maxi = INT_MIN, n = candies.size();
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, candies[i]);
        }

        vector<bool> ans(n, false);
        for(int i = 0; i < n; i++)
        {
            if(candies[i] + extraCandies >= maxi)
                ans[i] = true;
        }
        return ans;
    }
};