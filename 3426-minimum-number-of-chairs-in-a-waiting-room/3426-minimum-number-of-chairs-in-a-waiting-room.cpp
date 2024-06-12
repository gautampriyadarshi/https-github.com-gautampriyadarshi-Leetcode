class Solution {
public:
    int minimumChairs(string s) 
    {
        int count = 0, maxi = INT_MIN;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'E')
                count++;
            else
                count--;
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};