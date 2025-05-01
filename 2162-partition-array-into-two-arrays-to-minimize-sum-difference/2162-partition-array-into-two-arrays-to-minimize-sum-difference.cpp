// Best explanation why Tabulation is failing.
/*
https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/3606054/why-tabulation-not-working-what-is-meet-in-middle-all-questions-answered
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums) 
    {
        int arraySize = nums.size(); 
        int subarraySize = arraySize / 2; 

        vector<vector<int>> leftSums(subarraySize + 1), rightSums(subarraySize + 1); 
        int totalSum = accumulate(nums.begin(), nums.end(), 0); 

        // Generate all possible subarrays using bitmasks
        for (int bitmask = 0; bitmask < (1 << subarraySize); bitmask++) 
        {
            int subarrayElements = 0; 
            int leftSum = 0, rightSum = 0; 

            for (int i = 0; i < subarraySize; i++) 
            {
                if (bitmask & (1 << i)) 
                {
                    subarrayElements++; 
                    leftSum += nums[i]; 
                    rightSum += nums[i + subarraySize]; 
                }
            }

            leftSums[subarrayElements].push_back(leftSum);
            rightSums[subarrayElements].push_back(rightSum);
        }

        for (int i = 0; i < subarraySize; i++) 
        {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int minDifference = abs(totalSum - 2 * leftSums[subarraySize][0]); 

        for (int i = 1; i < subarraySize; i++) 
        {
            for (auto sum : leftSums[i]) 
            {
                int targetSum = (totalSum - 2 * sum) / 2; 
                int rightSubarrayIndex = subarraySize - i; 

                auto itr = lower_bound(rightSums[rightSubarrayIndex].begin(), 
                rightSums[rightSubarrayIndex].end(), targetSum);

                if (itr != rightSums[rightSubarrayIndex].end()) 
                { 
                    minDifference = min(minDifference, 
                    abs(totalSum - 2 * (sum + *itr))); 
                }
            }
        }
        return minDifference; 
    }
};