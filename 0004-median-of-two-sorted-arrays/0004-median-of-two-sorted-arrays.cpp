class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        for(int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();

        if(n % 2 != 0)
            return (double)(nums1[n/2]);
        
        double x = (double)nums1[n/2-1], y = (double)nums1[n/2];

        return (x+y)/2;
    }
};