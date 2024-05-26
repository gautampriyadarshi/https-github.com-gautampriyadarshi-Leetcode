class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int k;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    for(k = j+1; k < nums2.size(); k++)
                    {
                        if(nums2[k] > nums1[i])
                        {
                            nums1[i] = nums2[k];
                            break;
                        }
                    }

                    if(k == nums2.size())
                        nums1[i] = -1;
                    break;
                }
            }
        }
        return nums1;
    }
};