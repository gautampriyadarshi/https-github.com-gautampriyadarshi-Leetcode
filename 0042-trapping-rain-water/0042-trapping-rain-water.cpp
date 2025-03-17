class Solution {
public:
    int trap(vector<int>& height) 
    {
        int total = 0, l = 0, r = height.size()-1;
        int lmax = 0, rmax = height[r];

        while(l < r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] < lmax)
                    total += lmax - height[l]; // Water trapped on the left
                else
                    lmax = height[l];
                
                l++;
            }
            else
            {
                if(height[r] < rmax)
                    total += rmax - height[r]; // Water trapped on the right
                else
                    rmax = height[r];

                r--;
            }
        }
        return total;
    }
};