class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        int help = sqrt(num);
        if(help * help == num)
            return true;
            
        return false;
    }
};