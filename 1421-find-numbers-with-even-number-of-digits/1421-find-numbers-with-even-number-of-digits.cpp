class Solution {
    bool Number(int x)
    {
        int count = 0;
        while(x > 0)
        {
            count++;
            x /= 10;
        }

        if(count % 2 == 0)
            return true;
        
        return false;
    }
public:
    int findNumbers(vector<int>& nums) 
    {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(Number(nums[i]))
                count++;
        }
        return count;
    }
};