class Solution {
public:
    long long coloredCells(int n) 
    {
        if(n == 1)
            return 1;
        
        long long ans = 1, x = 4;
        for(int i = 2; i <= n; i++, x += 4)
        {
            ans += x;
        }
        return ans;
    }
};