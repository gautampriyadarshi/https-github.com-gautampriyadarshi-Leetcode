class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if(n == 1)
            return 1;
        
        int count2 = 1;
        int count3 = 1;
        int count5 = 1;
        
        int val1;
        int val2;
        int val3;
        
        vector<int> dp(n+1 ,0);
        dp[1] = 1;                 //first ugly number be 1
        
        for(int i = 2; i <= n; i++)
        {
            val1 = 2*dp[count2];
            val2 = 3*dp[count3];
            val3 = 5*dp[count5];
            
            int result = min(val1, min(val2, val3));
            
            if(result == val1)
                count2++;
            
            if(result == val2)
                count3++;

            if(result == val3)
                count5++;

            dp[i] = result;
        }
        return dp[n];
    }
};