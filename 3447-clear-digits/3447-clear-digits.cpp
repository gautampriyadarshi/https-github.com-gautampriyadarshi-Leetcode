class Solution {
public:
    string clearDigits(string s) 
    {
        string ans = "";
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                while(j >= 0)
                {
                    if(s[j] >= 'a' && s[j] <= 'z')
                    {
                        s[j] = '#';
                        break;
                    }
                    else
                        j--;
                }
            }
            else
            {
                if(s[i] != '#')
                    ans += s[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};