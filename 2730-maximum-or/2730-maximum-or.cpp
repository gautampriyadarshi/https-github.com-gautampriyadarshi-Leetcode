class Solution {
    long long solve(int n, int k) 
    {
        long long num = n;
        while(k-- > 0)
        {
            num *= 2;
        }
        return num;
    }
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> suff(n, 0);

        for(int i = n-2; i >= 0; i--) 
        {
            suff[i] = suff[i+1] | nums[i+1]; 
        }

        long long ans = 0;
        long long pre = 0;
        for(int i = 0; i < n; i++) 
        {
            long long a = pre | solve(nums[i],k) | suff[i];
            pre = pre | nums[i];
            ans = max(ans,a);
        }
        return ans;

        // TLE: 1202/1214 cases passed:
        /*  long long maxi = LLONG_MIN;
        int i = 0;
        while(i < nums.size())
        {
            int count = k;
            long long ans = 0;
            vector<long long> help(begin(nums), end(nums));
            for(int j = 0; j < nums.size(); j++)
            {
                if(j == i)
                {
                    while(count > 0)
                    {
                        help[i] *= 2;
                        count--;
                    }

                    ans = ans | help[i];
                }
                else
                    ans = ans | nums[j];
            }
            maxi = max(maxi, ans);
            i++;
        }
        return maxi;    */
    }
};