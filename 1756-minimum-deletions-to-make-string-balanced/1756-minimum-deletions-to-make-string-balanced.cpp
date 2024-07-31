class Solution {
public:
    int minimumDeletions(string s) 
    {
        int countB = 0, ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'b')
                countB++;
            else if(countB > 0)
            {
                ans++;
                countB--;
            }
        }
        return ans;
    }
};