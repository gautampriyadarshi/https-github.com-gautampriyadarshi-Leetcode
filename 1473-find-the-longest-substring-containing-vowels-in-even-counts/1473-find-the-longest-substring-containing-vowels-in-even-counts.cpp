class Solution {
public:
    int findTheLongestSubstring(string s) 
    {
        vector<int> map(32, -2);
        map[0] = -1;

        int maxLen = 0, mask = 0;

        for (int i = 0; i < s.size(); ++i) 
        {
            switch (s[i]) 
            {
                case 'a': mask ^= 1;
                    break;
                case 'e': mask ^= 2;
                    break;
                case 'i': mask ^= 4;
                    break;
                case 'o': mask ^= 8;
                    break;
                case 'u': mask ^= 16;
                    break;
            }

            if (map[mask] == -2) 
                map[mask] = i;
            else 
                maxLen = max(maxLen, i - map[mask]);
        }
        return maxLen;
    }
};