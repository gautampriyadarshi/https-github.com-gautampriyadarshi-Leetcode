class Solution {
public:
    string sortString(string s) 
    {   
        map<char,int> mp;
        string ans = "";
        int n = s.size();
        for(char ch : s)
        {
            mp[ch]++;
        }
        int i = 0;
        bool check = true;
        while(i < n)
        {
            if(check)
            {
                for(auto it = mp.begin(); it != mp.end(); it++)
                {
                    if(it-> second >= 1)
                    {
                        ans += it-> first;
                        it-> second--;
                        i++;
                    }
                }
                check = false;
            }
            else if(!check)
            {
                auto it = mp.end();
                do
                {
                    it--;
                    if(it-> second >= 1)
                    {
                        ans += it-> first;
                        it-> second--;
                        i++;
                    }
                } while(it != mp.begin());
                check = true;
            }
        }
        return ans;
        /*
        int n = s.size(), k = 0;
        bool up = true;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        sort(s.begin(), s.end());

        string ans = "";
        ans += s[0];
        mp[s[0]]--;

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(up == true)
                {
                    if(mp[s[j]] > 0 && s[j] > ans[k])
                    {
                        ans += s[j];
                        k++;
                        mp[s[j]]--;
                    }
                }
                else
                {
                    if(mp[s[j]] > 0 && s[j] < ans[k])
                    {
                        ans += s[j];
                        k++;
                        mp[s[j]]--;
                    }
                }
            }
            
            if(up == true)
            {
                up = false;
                if(mp[ans[k]] > 0)
                {
                    ans += ans[k];
                    k++;
                    mp[ans[k]]--;
                }
            }
            else if(up == false)
            {
                up = true;
                if(mp[ans[k]] > 0)
                {
                    ans += ans[k];
                    k++;
                    mp[ans[k]]--;
                }
            }
        }
        return ans; */
    }
};