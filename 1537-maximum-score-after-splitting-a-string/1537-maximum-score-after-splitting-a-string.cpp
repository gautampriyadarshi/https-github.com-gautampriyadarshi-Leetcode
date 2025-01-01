class Solution {
public:
    int maxScore(string s) 
    {
        int maxi = INT_MIN, zero = 0, ones = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
                ones++;
        }

        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i] == '0')
                zero++;
            else
                ones--;
            
            maxi = max(maxi, zero + ones);
        }
        return maxi;
    }
};