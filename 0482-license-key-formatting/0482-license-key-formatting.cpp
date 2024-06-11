class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string raw = "", ans = "", help = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '-')
                raw += s[i];
        }

        if(raw.size() == 0)
            return "";

        int num = k;
        for(int i = raw.size()-1; i >= 0; i--)
        {
            if(num > 0)
            {
                help += raw[i];
                num--;
            }
            
            if(num == 0)
            {
                ans += help + '-';
                help = "";
                num = k;
            }
        }
        ans += help;

        int x = ans.size()-1;
        if(ans[x] == '-')
            ans.pop_back();
        
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] >= 'a' && ans[i] <= 'z')
                ans[i] = ans[i] - 32;
        }
        return ans;
    }
};