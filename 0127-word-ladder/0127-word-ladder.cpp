class Solution {
public:
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    int ladderLength(string start, string target, vector<string>& arr) 
    {
        unordered_set<string> st(arr.begin(), arr.end());
        int res = 0, m = start.length();

        queue<string> words;
        words.push(start);

        while (!words.empty()) 
        {
            res++;
            int len = words.size();
            
            for (int i = 0; i < len; ++i) 
            {
                string word = words.front();
                words.pop();

                // For every character of the word
                for (int j = 0; j < m; ++j) 
                {
                    // Retain the original character at the current position
                    char ch = word[j];

                    // Replace the current character with every possible lowercase alphabet
                    for (char c = 'a'; c <= 'z'; ++c) 
                    {
                        word[j] = c;

                        // skip the word if already added or not present in set
                        if (st.find(word) == st.end())
                            continue;
                            
                        // If target word is found
                        if (word == target)
                            return res + 1;

                        // remove the word from set
                        st.erase(word);

                        // And push the newly generated word which will be a part of the chain
                        words.push(word);
                    }

                    // Restore the original character
                    // at the current position
                    word[j] = ch;
                }
            }
        }
        return 0;
    }
};