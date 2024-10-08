class Solution {
public:
    int minSwaps(string s) 
    {
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ans += (s[i] == '[') - (s[i] == ']');

            if(ans < 0)
                ans = 0;
        }
        return (ans + 1)/2;
    }
};