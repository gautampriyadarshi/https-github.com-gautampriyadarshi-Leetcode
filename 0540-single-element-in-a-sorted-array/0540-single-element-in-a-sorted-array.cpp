class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) 
        {
            int mid = l + (r - l) / 2;
            
            // We want 'mid' to always point to the start of a potential pair.
            // Before the single element, pairs start at even indices.
            // If 'mid' is odd, decrement it by 1 to make it even.
            if (mid % 2 == 1) 
                mid--;
            
            if (nums[mid] == nums[mid + 1]) 
            {
                // If they match, the pattern of pairs is unbroken.
                // The single missing element must be further to the r.
                // We move 'l' past this current pair.
                l = mid + 2;
            } 
            else 
            {
                // If they don't match, the pattern has been broken.
                // The single element is either at 'mid' or somewhere to the l.
                // We bring 'r' down to 'mid' to narrow the search space.
                r = mid;
            }
        }
        
        // When l == r, the search space has shrunk to a single element.
        return nums[l];
    }
};