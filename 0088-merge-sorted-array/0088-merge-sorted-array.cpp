class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < nums1.size(); j++)
            {
                if(nums1[j] == 0)
                {
                    nums1[j] = nums2[i];
                    break;
                }
            }
        }

        sort(nums1.begin(), nums1.end());
    }
};