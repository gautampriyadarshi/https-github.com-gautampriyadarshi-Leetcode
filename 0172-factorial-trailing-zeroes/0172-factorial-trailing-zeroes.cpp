class Solution {
public:
    int trailingZeroes(int n) 
    {
        if(n <= 4)
            return 0;
        else if(n > 4 && n < 10)
            return 1;
        else if(n >= 10 && n <= 14)
            return 2;
        
        int count = 0;
        for(int i = 5; n/i >= 1; i = i*5)
        {
            count += n/i; 
        }
        return count;
    }
};