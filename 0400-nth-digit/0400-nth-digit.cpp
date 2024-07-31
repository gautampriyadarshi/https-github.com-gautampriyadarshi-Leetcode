class Solution {
public:
    int findNthDigit(int n) 
    {
        long long digit = 1, base = 1;
        while (n > 9 * digit * base)
        {
            n -= 9*digit*base;
            digit += 1;
            base *= 10;
        }

        int q = (n-1) / digit;
        int rem = (n-1) % digit;

        return to_string(base+q)[rem] - '0';
        
        /*
        if(n <= 9)
            return n;
            
        int ans = 0, count = 0;
        string help = "";
        for(int i = 1; i <= n; i++)
        {
            help += to_string(i);
        }

        for(int i = 0; i < help.size(); i++)
        {
            count++;
            if(count == n)
            {
                ans = help[i] - '0';
                break;
            }
        }
        return ans; */
    }
};