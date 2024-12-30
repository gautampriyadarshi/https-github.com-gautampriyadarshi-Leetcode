class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        for(int i = n; i >= 2; i--)
        {
            int perimeter = 0;
            int x = nums[i], y = nums[i-1], z = nums[i-2];

            if(x + y > z)
            {
                if(x - y < z)
                {
                    perimeter = x+y+z;
                    maxi = max(maxi, perimeter);
                }
            }
            else if(x + z > y)
            {
                if(x - z < y)
                {
                    perimeter = x+y+z;
                    maxi = max(maxi, perimeter);
                }
            }
            else if(z + y > x)
            {
                if(y - z < x)
                {
                    perimeter = x+y+z;
                    maxi = max(maxi, perimeter);
                }
            }
        }

        if(maxi == INT_MIN)
            return 0;
        
        return maxi;
    }
};