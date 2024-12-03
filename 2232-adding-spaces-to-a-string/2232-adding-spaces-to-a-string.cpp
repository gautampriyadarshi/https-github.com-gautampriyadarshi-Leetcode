class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        sort(spaces.begin(), spaces.end());
        string ans = "";
        int i = 0, j = 0;
        while(j < spaces.size())
        {
            if(i == spaces[j])
            {
                ans += ' ';
                j++;
            }
            ans += s[i++];
        }

        while(i < s.size())
        {
            ans += s[i++];
        }
        return ans;
    }
};