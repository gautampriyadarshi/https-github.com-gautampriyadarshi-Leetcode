class Solution {
    bool vowel(char word)
    {
        if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u' ||
            word == 'A' || word == 'E' || word == 'I' || word == 'O' || word == 'U')
                return true;
            
        return false;
    }

    bool consonent(char word)
    {
        if((word >= 'a' && word <= 'z' && !vowel(word)) || (word >= 'A' && word <= 'Z' && !vowel(word)))
            return true;
        
        return false;
    }
public:
    bool isValid(string word) 
    {
        if(word.size() < 3)
            return false;
        
        int vw = 0, con = 0, num = 0;
        for(int i = 0; i < word.size(); i++)
        {
            if(vowel(word[i]))
                vw++;
            
            else if(consonent(word[i]))
                con++;
            
            else if(word[i] >= '0' && word[i] <= '9')
                num++;
        }

        if(vw == 0 || con == 0)
            return false;
        
        if(word.size() != (num + vw + con))
            return false;
        
        return true;
    }
};