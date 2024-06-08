class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>m;
        int s=0;
        int c=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            // calculating prefix sum [sum from 0 to i]
            s+=nums[i];  

            if(m.find(s-k)!=m.end())
            {
                // adding no of prefix sums encountered till now with sum s-k.
                c+=m[s-k];  
            }

            // adding prefix sum to the map
            m[s]++; 
        }
        return c;
    }
};