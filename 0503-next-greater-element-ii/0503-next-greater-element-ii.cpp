class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // Monotonic stack storing INDICES

        // We traverse the array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) 
        {
            // Use modulo to wrap around the index
            int currentNum = nums[i % n];

            // Standard Monotonic Decreasing Stack logic:
            while (!st.empty() && nums[st.top()] < currentNum) 
            {
                ans[st.top()] = currentNum;
                st.pop();
            }

            // Only push indices from the first pass to avoid redundant work 
            // (We only need to find answers for indices 0 to n-1)
            if (i < n) 
                st.push(i);
        }
        return ans;
    }
};