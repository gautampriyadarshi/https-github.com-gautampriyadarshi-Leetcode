class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0)
            return false;
       
        if(n == 1)
           return true;

        bool solve;
        if(n % 3 == 0)
            solve = isPowerOfThree(n/3);
        
        if(solve)
            return true;

        return false;
    }
};