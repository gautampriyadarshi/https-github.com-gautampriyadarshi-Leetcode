class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        /* // TC: O((m+n)log(m+n))
        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());   */ 

        /***********TC: O(m+n) ***********/
        int i = m - 1;       
        int j = n - 1;       
        int k = m + n - 1;   // Pointer for the end of nums1 (where we place the largest element)
        
        while (j >= 0) 
        {
            // If nums1 still has valid elements and its current element is larger
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } 
            else {
                // Otherwise, the element from nums2 is larger (or nums1 is exhausted)
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};