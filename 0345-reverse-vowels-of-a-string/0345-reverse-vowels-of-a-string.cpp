class Solution {
    bool isVowel(char a)
    {
        if(a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U')
        {
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
            else if(isVowel(s[m]))
                n--;
            else if(isVowel(s[n]))
                m++;
            else
            {
                m++;
                n--;
            }
        }
        return s;
    }
};