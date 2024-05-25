class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        // int n1 = str1.size();
        // int n2 = str2.size();

        // string word1 = str1, word2 = str2;
        // sort(word1.begin(), word1.end());
        // sort(word2.begin(), word2.end());
        // if(word1[0] != word2[0])
        //     return "";

        // string help = "";
        // for(int i = 0; i < n2; i++)
        // {
        //     string ans = "";
        //     int x = 1;
        //     help += str2[i];
        //     for(int j = 0; j < n1/x; j++)
        //     {
        //         ans += help;
        //         if(ans == str1)
        //         {
        //             if(n2 % 2 != 0 || n1 % n2 != 0)
        //                 return help;
        //         }
        //     }
        // }

        // return help;

        if(str1+str2 != str2+str1) 
            return "";

        int d = gcd(str1.size(),str2.size());
        return str1.substr(0,d);
    }
};