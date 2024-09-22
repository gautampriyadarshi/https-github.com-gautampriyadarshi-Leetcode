class Solution {
public:
    int findKthNumber(int n, int k) 
    {
        // TLE: 61/69 cases passed.
    /*  int ans;
        long long int x = 1;

        for(int i = 0; i < n; i++)
        {
            ans = x;

            if(i == k-1)
                return ans;

            if (x * 10 > n)
            {
                if (x == n) 
                    x /= 10;

                x++;
                while(x % 10 == 0)
                {
                    x /= 10;
                } 
            } 
            else 
                x *= 10;          
        }
        return ans; */

        int s = 1;
        k--;
        while(k>0)
        {
            int steps = 0;
            long long first = s;
            long long last = s+1;

            while(first <= n)
            {
                steps += min((long long)n+1,last) - first;
                first *= 10;
                last *= 10;
            }
            if(steps <=k)
            {
                s++;
                k -= steps;
            }
            else
            {
                s *= 10;
                k--;
            }
        }
        return static_cast<int>(s);
    }
};