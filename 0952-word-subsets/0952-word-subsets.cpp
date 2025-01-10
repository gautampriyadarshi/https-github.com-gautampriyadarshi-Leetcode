class Solution {
    bool helper(vector<int>& freq2, vector<int>& freq1) 
    {
        bool flag = true;
        for (int i = 0; i < 26; i++) 
        {
            if (freq1[i] < freq2[i]) 
                flag = false;
            
            freq1[i] = 0;
        }
        return flag;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> freq(26, 0), temp(26, 0);
        vector<string> ans;

        for (auto& str : words2) 
        {
            for (auto& ch : str) 
            {
                temp[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) 
            {
                freq[i] = max(freq[i], temp[i]);
                temp[i] = 0;
            }
        }

        for (auto& word : words1) 
        {
            for (auto& ch : word) 
            {
                temp[ch - 'a']++;
            }

            if (helper(freq, temp)) 
                ans.push_back(word);
        }
        return ans;
    }
};