class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.size() > haystack.size())
            return -1;

        int i = 0, j = 0;
        while(i < haystack.size())
        {
            if(haystack[i] != needle[j])
                i++;
            else
            {
                int ans = i, size = needle.size();
                string k = "";
                while(size--)
                {
                    if(i < haystack.size())
                        k += haystack[i++];
                }
                if(k == needle) 
                    return ans;

                i = ans+1;
            }
        }
        return -1;
    }
};