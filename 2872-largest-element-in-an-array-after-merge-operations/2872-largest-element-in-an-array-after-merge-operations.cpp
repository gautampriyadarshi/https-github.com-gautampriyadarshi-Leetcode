class Solution {
public:
    long long maxArrayValue(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];

        vector<long long> vec;

        for(int i = 0; i < nums.size(); i++)
        {
            vec.push_back(nums[i]);
        }
        
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(vec[i] >= vec[i+1])
                vec[i+1] = vec[i]+vec[i+1];
        }

        return *max_element(vec.begin(), vec.end());
    }
};