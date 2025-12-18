class Solution {
    static bool check(const string& a, const string& b)
    {
        return a.size() < b.size();
    }
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(), strs.end(), check);
        string ans = strs[0], test = "";

        int j = 0, k = 0;
        for(int i = 1; i < strs.size(); i++)
        {
            while(j < ans.size())
            {
                if(ans[0] != strs[i][0])
                    return "";

                if(ans[j] == strs[i][k])
                {
                    test += ans[j];
                    j++;
                    k++;
                }
                else
                    break;
            }
            ans = test;
            test = "";
            j = 0; k = 0;
        }
        return ans;
    }
};