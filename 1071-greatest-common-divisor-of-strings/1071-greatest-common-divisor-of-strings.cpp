class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        int len1 = str1.size(), len2 = str2.size();
        int GCD = gcd(len1, len2);
        int j = 0;

        if(GCD < len2)
        {
            for(int k = 0; k < GCD; k++)
            {
                if(str2[k] != str2[k + GCD])
                    return "";
            }
        }
        

        for(int i = 0; i < len1; i++)
        {
            if(j == len2)
                j = 0;

            if(str1[i] != str2[j])
                return "";
            else
                j++;
        }

        return str2.substr(0, GCD);
    }
};