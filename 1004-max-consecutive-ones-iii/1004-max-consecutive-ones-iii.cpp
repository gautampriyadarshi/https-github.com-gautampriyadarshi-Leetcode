class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int count = 0, maxi = INT_MIN, x = k, j = 0;
        vector<int> indexs;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                indexs.push_back(i);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(x > 0)
            {
                if(nums[i] == 0)
                    x--;
                
                count++;
                maxi = max(count, maxi);
            }
            else if(x == 0)
            {
                if(nums[i] == 0)
                {
                    count = (i-indexs[j]);
                    cout << count << " ";
                    // count++;
                    j++;
                }
                else
                    count++;
                
                maxi = max(maxi, count);
            }
        }   
        return maxi;
    }
};