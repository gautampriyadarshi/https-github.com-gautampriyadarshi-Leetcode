class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int len = INT_MAX;
        long long sum = 0;
        vector<int> positive;
        for (int i = 0, j = 0; j < nums.size(); ++j) 
        {
            sum += nums[j];
            if (nums[j] < 0) 
            {
                int r = nums[j];
                while (!positive.empty()) 
                {
                    int cur = positive.back();
                    r += nums[cur];
                    nums[cur] = r;
                    nums[j] = 0;
                    positive.pop_back();

                    if (r < 0 && !positive.empty() && positive.back() >= i) 
                        nums[cur] = 0;
                    
                    else 
                    {
                        positive.push_back(cur);
                        break;
                    }
                }
            }
            else 
            {
                positive.push_back(j);

                while (i <= j && (sum-nums[i] >= k || nums[i] <= 0))
                    sum -= nums[i++];
                
                if (sum >= k) 
                    len = min(len, j - i + 1);
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};