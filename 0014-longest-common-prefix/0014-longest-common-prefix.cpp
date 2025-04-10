class Solution {
public:
    string longestCommonPrefix(vector<string>& str) 
    {
        if(str.size() == 1)
            return str[0];
        
        sort(str.begin(), str.end());
        int n = str.size();
        string ans = "";
        string first = str[0], last = str[n-1];
        for(int i = 0; i < min(first.size(), last.size()); i++)
        {
            if(first[i] != last[i])
                return ans;
            
            ans += first[i];
        }

        return ans;
    }
};