class Solution {
    int sumTotal(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) 
    {
        unordered_map<int, vector<int>> mp;
        for(int i = 1; i <= n; i++)
        {
            if(i <= 9)
                mp[i].push_back(i);
            else
            {
                int sum = sumTotal(i);
                mp[sum].push_back(i);
            }
        }

        int maxi = 0, count = 0;
        for(auto x: mp)
        {
            int y = x.second.size();
            maxi = max(maxi, y);
        }
        
        for(auto x: mp)
        {
            if(x.second.size() == maxi)
                count++;
        }
        return count;
    }
};