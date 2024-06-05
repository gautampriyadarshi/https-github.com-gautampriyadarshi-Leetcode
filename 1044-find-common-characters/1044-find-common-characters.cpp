class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        unordered_map<char,int> m;
        for(char ch='a';ch<='z';++ch){
            m[ch] = INT_MAX;
        }
        int n = words.size();
        for(int i=0;i<n;++i){
            unordered_map<char,int> m2;
            for(char c : words[i]){
                m2[c]++;
            }
            for(char ch ='a';ch<='z';++ch){
                m[ch] = min(m2[ch],m[ch]);
            }
        }
        vector<string> ans;
        // int i = 0;
        for(char ch='a';ch<='z';++ch){
            while(m[ch]-- > 0){
                ans.push_back(string(1,ch));
            }
        }
        return ans;
    }
};