class Solution {
    bool isVowel(char x)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            return true;
        
        return false;
    }

    bool isStartEndVowel(string &str)
    {
        int n = str.size();
        if(isVowel(str[0]) && isVowel(str[n-1]))
            return true;
        
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        // TLE: 92/93 cases passed
        /* vector<int> ans;
        int count = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int m = queries[i][0], n = queries[i][1];
            for(int j = m; j <= n; j++)
            {
                int p = words[j].size();

                if(isVowel(words[j][0]) && isVowel(words[j][p-1]))
                    count++;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans; */

        int n = words.size(), m = queries.size();

        vector<int> prefix(n), ans;
        prefix[0] = isStartEndVowel(words[0]);

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + isStartEndVowel(words[i]);
        }

        for(int i = 0; i < m; i++)
        {
            int left = queries[i][0], right = queries[i][1], totalStr = 0;

            if(left != 0)
                totalStr = prefix[right] - prefix[left-1];
            else
                totalStr = prefix[right];
            
            ans.push_back(totalStr);
        }
        return ans;
    }
};