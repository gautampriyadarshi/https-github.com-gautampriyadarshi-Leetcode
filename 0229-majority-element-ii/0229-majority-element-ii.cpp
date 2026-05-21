class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int num1 = 0, num2 = 0;
        int count1 = 0, count2 = 0;
        
        // Pass 1: Find potential candidates
        for (int x : nums) 
        {
            if (x == num1) 
                count1++;
            else if (x == num2) 
                count2++;
            else if (count1 == 0) 
            {
                num1 = x;
                count1 = 1;
            }
            else if (count2 == 0) 
            {
                num2 = x;
                count2 = 1;
            }
                
            else {
                // If the current number doesn't match either candidate,
                // and both candidates have votes, we decrement both counts.
                count1--;
                count2--;
            }
        }
        
        // Pass 2: Verify if candidates actually appear more than n/3 times
        count1 = 0;
        count2 = 0;

        for (int x : nums) 
        {
            if (x == num1) 
                count1++;
            else if (x == num2) 
                count2++;
        }
        
        vector<int> ans;
        int n = nums.size();
        
        if (count1 > n / 3) 
            ans.push_back(num1);
        if (count2 > n / 3) 
            ans.push_back(num2);
        
        return ans;
    }
};