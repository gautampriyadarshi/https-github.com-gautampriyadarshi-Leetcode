class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
    /*  // TLE: 17/19 cases passed:
        vector<int> vec;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                int x = abs(nums[i]-nums[j]);
                vec.push_back(x);
            }
        }

        sort(vec.begin(), vec.end());
        return vec[k-1];    */
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0, j = 0;

            for (int i = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= mid)
                    j++;
                cnt += j - i - 1;
            }

            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};