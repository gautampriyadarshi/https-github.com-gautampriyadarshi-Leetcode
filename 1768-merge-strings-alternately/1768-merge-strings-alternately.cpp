class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();
        string ans = "";

        int i = 0, j = 0, k = 0;
        while(k < m + n)
        {
            if(i < m) 
                ans += word1[i++];
            
            if(j < n)
                ans += word2[j++];
            
            k++;
        }
        return ans;
    }
};