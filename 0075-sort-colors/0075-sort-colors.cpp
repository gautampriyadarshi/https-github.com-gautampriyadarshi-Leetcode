class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int> vec = nums;
        nums.clear();

        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == 0)
                nums.push_back(vec[i]);
        }

        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == 1)
                nums.push_back(vec[i]);
        }

        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == 2)
                nums.push_back(vec[i]);
        }
    }
};