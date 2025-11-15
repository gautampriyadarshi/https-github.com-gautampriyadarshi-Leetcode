class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int zero = 0, one = 0, two = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)    
                zero++;
            else if(nums[i] == 1)   
                one++;
            else
                two++;
        }

        nums.clear();
        for(int i = 0; i < n; i++)
        {
            if(zero > 0)
            {
                nums.push_back(0);
                zero--;
                continue;
            }
            else if(one > 0)
            {
                nums.push_back(1);
                one--;
                continue;
            }
            else
            {
                nums.push_back(2);
                two--;
                continue;
            }
        }
    }
};