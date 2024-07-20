class Solution {
public:
    int minimumLength(string s) 
    {
        // for(int i = 1; i < s.size()-1; i++)
        // {
        //     int y = i-1, x = i+1;
        //     bool left = false;
        //     while(y >= 0)
        //     {
        //         if(s[i] == s[y])
        //         {
        //             s[y] = '#';
        //             left = true;
        //             break;
        //         }
        //         else
        //             y--;
        //     }

        //     while(left == true && x < s.size())
        //     {
        //         if(s[i] == s[x])
        //         {
        //             s[x] = '#';
        //             break;
        //         }
        //         else
        //             x++;
        //     }
        // }

        // int count = 0;
        // for(int i = 0; i < s.size(); i++)
        // {
        //     cout << s[i];
        //     if(s[i] != '#')
        //         count++;
        // }
        // return count;

        int count = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;

            if(mp[s[i]]>2)
            {
                mp[s[i]]=1;
                count -= 2;
            }
        }
        return count;
    }
};