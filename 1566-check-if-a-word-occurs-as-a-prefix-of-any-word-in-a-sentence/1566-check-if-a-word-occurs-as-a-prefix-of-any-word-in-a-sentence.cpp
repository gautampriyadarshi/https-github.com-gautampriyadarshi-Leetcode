class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        int ans = 1;
        int prev = -1;
        int j = 0;
        bool current = true;
        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] == ' ')
            {
                ans++;
                current = true;
                j = 0;
            }
            else if(current && sentence[i] == searchWord[j])
                j++;
            else
            {
                current = false;
                j = 0;
            }

            if(j == searchWord.size())
                return ans;
        }
        return -1;
    }
};