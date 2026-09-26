class Solution {
    bool isVowel(char a)
    {
        if(a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' 
        || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U') {
            return true;
        }

        return false;
    }
public:
    string reverseVowels(string s) 
    {
        int m = 0, n = s.size()-1;
        while(m <= n)
        {
            if(isVowel(s[m]) && isVowel(s[n]))
            {
                swap(s[m], s[n]);
                m++;
                n--;
            }
            else if(isVowel(s[m]))  // s[n] is a consonent
                n--;
            else if(isVowel(s[n]))  // s[m] is a consonent
                m++;
            else    // both are consonent
            {
                m++;
                n--;
            }
        }
        return s;
    }
};