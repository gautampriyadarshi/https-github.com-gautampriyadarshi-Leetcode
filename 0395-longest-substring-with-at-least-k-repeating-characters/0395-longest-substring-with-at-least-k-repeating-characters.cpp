class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
            mp[s[i]]++;

        int i = 0;
        while(i < n && mp[s[i]] >= k){
            i++;
        }
            
        if(i == n)
            return n;
        
        // recursively search for valid substrings in between invalid characters
        int left = longestSubstring(s.substr(0, i), k);

        while (i < n && mp[s[i]] < k) {
            i++;
        }

        int right = (i < n) ? longestSubstring(s.substr(i), k) : 0;

        return max(left, right);
    }
};