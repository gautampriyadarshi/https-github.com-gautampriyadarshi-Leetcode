class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) 
        {
            // 1. Found a new candidate for the smallest first element
            if (x <= first) 
                first = x;

            // 2. Greater than 'first', but smaller than or equal to 'second'
            else if (x <= second) 
                second = x;

            // 3. Greater than both 'first' and 'second' -> Valid triplet found!
            else 
                return true;
        }
        return false;
    }
};