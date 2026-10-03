class Solution {
    bool isVowel(char x)
    {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            return true;
        
        return false;
    }
public:
    int maxVowels(string s, int k) 
    {
        int count = 0, maxi = INT_MIN;
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]))
                count++;
            
            maxi = max(maxi, count);
        }

        for(int i = k; i < s.size(); i++)
        {
            if(isVowel(s[i-k]))
                count--;
            
            if(isVowel(s[i]))
                count++;
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};