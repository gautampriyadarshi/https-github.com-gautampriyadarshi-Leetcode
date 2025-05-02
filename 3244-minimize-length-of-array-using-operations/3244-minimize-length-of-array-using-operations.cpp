class Solution {
    int help(int i, int j)
    {
        while(j != 0)
        {
            int temp = j;
            j = i % j;
            i = temp;
        }
        return i;
    }
public:
    int minimumArrayLength(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int x = nums.size();
        
        if(x > 2 && nums[0] != nums[1])
            return 1;
        
        int p = nums[0];
        for(int i: nums)
        {
            p = help(p,i);
        }
        
        int count = 0;
        for(int i: nums)
        {
            if(i == p)
                count++;
        }
        
        int y = (count+1)/2;
        return max(1, y);
        
    }
};