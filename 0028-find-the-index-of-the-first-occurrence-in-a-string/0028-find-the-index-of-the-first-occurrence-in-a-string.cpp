class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int m = haystack.size();
        int n = needle.size();

        if (n == 0) 
            return 0;

        // 1. Preprocess needle to create LPS array
        vector<int> lps(n, 0);
        int prevLPS = 0, i = 1;
        while (i < n) 
        {
            if (needle[i] == needle[prevLPS])
                lps[i++] = ++prevLPS;
            else if (prevLPS == 0)
                lps[i++] = 0;
            else
                prevLPS = lps[prevLPS - 1];
        }

        // 2. Search haystack using LPS
        int hayIdx = 0, needleIdx = 0;
        while (hayIdx < m) {
            if (haystack[hayIdx] == needle[needleIdx]) {
                hayIdx++;
                needleIdx++;
            } else {
                if (needleIdx == 0) {
                    hayIdx++;
                } else {
                    // Use LPS to skip unnecessary comparisons
                    needleIdx = lps[needleIdx - 1];
                }
            }
            
            if (needleIdx == n) {
                return hayIdx - n; // Match found!
            }
        }

        return -1;
    }
};