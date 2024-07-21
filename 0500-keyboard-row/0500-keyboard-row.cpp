class Solution {
public:
    vector<string> findWords(vector<string>& words) 
    {
        string one = "qwertyuiop", two = "asdfghjkl", three = "zxcvbnm";
        unordered_map<char, int> mp;

        int i = 0;
        while(i < one.size())
        {
            char nw = toupper(one[i]);
            mp[one[i]] = 1;
            mp[nw] = 1;
            i++;
        }

        i = 0;
        while(i < two.size())
        {
            char nw = toupper(two[i]);
            mp[two[i]] = 2;
            mp[nw] = 2;
            i++;
        }

        i = 0;
        while(i < three.size())
        {
            char nw = toupper(three[i]);
            mp[three[i]] = 3;
            mp[nw] = 3;
            i++;
        }

        vector<string> ans;
        for(int j = 0; j < words.size(); j++)
        {
            bool fir = false, sec = false, thi = false; 
            for(int k = 0; k < words[j].size(); k++)
            {
                if(mp[words[j][k]] == 1)
                    fir = true;
                else if(mp[words[j][k]] == 2)
                    sec = true;
                else if(mp[words[j][k]] == 3)
                    thi = true;
            }

            if((fir && !sec && !thi) || (!fir && sec && !thi) || (!fir && !sec && thi))
                ans.push_back(words[j]);
        }
        return ans;
    }
};