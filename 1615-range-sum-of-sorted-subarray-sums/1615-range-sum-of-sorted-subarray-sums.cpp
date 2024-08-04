#define MOD 1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int> vec;
        int i = 0;
        while(i < nums.size())
        {
            long long int sum = 0;
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                vec.push_back(sum);
            }
            i++;
        }

        sort(vec.begin(), vec.end());
        int ans = 0;
        
        for(int k = left-1; k < right; k++)
        {
            ans = (ans + vec[k]) % MOD;
        }
        return ans;
    }
};