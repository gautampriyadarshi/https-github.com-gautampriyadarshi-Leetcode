class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        int ans = 0;
        
        for (int num : nums) 
        {
            // If the count drops to zero, we pick a new ans
            if (count == 0) 
                ans = num;
            
            // If the current number matches our ans, increment count.
            // Otherwise, decrement it.
            if (num == ans) 
                count++;
            else 
                count--;

        }
        return ans;
    }
};