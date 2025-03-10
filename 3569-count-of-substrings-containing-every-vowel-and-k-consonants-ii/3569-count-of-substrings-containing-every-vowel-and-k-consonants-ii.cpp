class Solution {
    bool isVowel(char X)
    {
        if(X == 'a' || X == 'e' || X == 'i' || X == 'o' || X == 'u')
            return true;
        
        return false;
    }

    long long atLeastK(string word, int k) 
    {
        int n = word.size(), consonants = 0, left = 0;
        long long ans = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < n; right++) 
        {
            if (isVowel(word[right])) 
                mp[word[right]]++;
            else 
                consonants++;

            while (mp.size() == 5 && consonants >= k) 
            {
                ans += n - right;

                if (isVowel(word[left])) 
                {
                    mp[word[left]]--;
                    if (mp[word[left]] == 0) 
                        mp.erase(word[left]); 
                } 
                else 
                    consonants--;
                
                left++;
            }
        }
        return ans;
    }
public:
    long long countOfSubstrings(string word, int k) 
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};