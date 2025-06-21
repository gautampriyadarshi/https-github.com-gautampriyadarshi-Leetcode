class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) 
    {
        if(target == (jug1 + jug2) || target == jug1 || target == jug2)
            return true;
        else if(jug1 + jug2 < target)
            return false;
        
        int d = __gcd(jug1, jug2);

        return (target % d == 0);
    }
};
