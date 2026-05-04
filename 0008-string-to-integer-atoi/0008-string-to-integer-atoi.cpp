class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int n = s.length();
        
        // 1. Skip leading whitespaces manually
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine signedness
        bool neg = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) 
        {
            if (s[i] == '-') 
                neg = true;
            
            i++;
        }

        // 3. Conversion and Rounding
        long long result = 0; // Use long long to catch overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') 
        {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
            // Check for overflow immediately
            if (neg && -result < -2147483648LL) 
                return INT_MIN;
            
            if (!neg && result > 2147483647LL) 
                return INT_MAX;
            
            i++;
        }

        if (neg) 
            return (int)-result;
    
        return (int)result;
    }
};