class Solution {
    static bool cmp(int x , int y) 
    {
        string xy = to_string(x) + to_string(y);
        string yx = to_string(y) + to_string(x);
        return xy > yx;
    }
public:
    string largestNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";

        for(int i = 0 ; i < nums.size() ; i++) 
        {
            ans += to_string(nums[i]);
        }

        if(ans[0] == '0')
           return "0";
           
        return ans;
    }
};