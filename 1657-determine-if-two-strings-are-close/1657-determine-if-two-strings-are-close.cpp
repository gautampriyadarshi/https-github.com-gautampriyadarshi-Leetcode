class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size() != word2.size())
            return false;
        
        map<char, int> mp1, mp2;
        for(int i = 0; i < word1.size(); i++) {
            mp1[word1[i]]++;
        }

        for(int i = 0; i < word2.size(); i++) {
            mp2[word2[i]]++;
        }

        // FIX 1: Ensure both strings have the exact same unique character set
        for(auto x: mp1)
        {
            if(mp2.find(x.first) == mp2.end())
                return false;
        }

        for(auto x: mp2)
        {
            if(mp1.find(x.first) == mp1.end())
                return false;
        }

        // FIX 2: Compare frequency distributions
        // Extract all frequency counts and verify their sorted orders match
        vector<int> freq1, freq2;
        for(auto x: mp1) 
            freq1.push_back(x.second);

        for(auto x: mp2) 
            freq2.push_back(x.second);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

// TC: O(n)
// SC: O(1)