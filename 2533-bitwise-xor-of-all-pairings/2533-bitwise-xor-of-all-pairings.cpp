class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        // Time limit exceeded: 38/42 cases passed.
        // Memory optimised by using the variable ans directly instead of first storing in vector and then calculating the answer by traversing the array again.

        if(nums1 == nums2)
            return 0;
        
        long long int x = 0, ans = nums1[0] ^ nums2[0];
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(i == 0 && j == 0)
                    continue;
                
                x = nums1[i] ^ nums2[j];
                ans ^= x;
                x = 0;
            }
        }
        
        return ans;
    }
};