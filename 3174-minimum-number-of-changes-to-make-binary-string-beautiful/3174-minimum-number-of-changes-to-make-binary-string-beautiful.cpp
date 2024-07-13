class Solution {
public:
    int minChanges(string s) 
    {
        // int mini = INT_MAX, count1 = 0, count0 = 0, x = INT_MAX;
        // bool ct1 = false, ct2 = false;
        // int n = s.size();

        // while(n > 2)
        // {
        //     for(int i = 0; i < n/2; i++)
        //     {
        //         if(s[i] == '0')
        //             count0++;
                
        //         if(s[i] == '1')
        //             count1++;
        //     }

        //     if(count1 == count0)
        //     mini = min(mini, count1);
        //     else if(count1 > count0)
        //         mini = min(mini, count0);
        //     else
        //         mini = min(mini, count1);

        //     if(count1 == 0)
        //         ct1 = true;

        //     count0 = 0;
        //     count1 = 0;

        //     for(int i = n/2; i < n; i++)
        //     {
        //         if(s[i] == '0')
        //             count0++;
                
        //         if(s[i] == '1')
        //             count1++;
        //     }

        //     if(count1 == count0)
        //         x = min(x, count1);
        //     else if(count1 > count0)
        //         x = min(x, count0);
        //     else
        //         x = min(x, count1);

        //     mini += x;

        //     if(count1 == 0)
        //         ct2 = true;

        //     if(ct1 && ct2)
        //         return mini;
        //     else if(mini == 0)
        //         return 1;
            
        //     count0 = 0;
        //     count1 = 0;
        //     n = n/2;
        // }

        // if(mini == INT_MAX)
        //     return 1;

        // return mini;

        int ans = 0;
        for (int i = 1; i < s.size(); i += 2)
        {
            if (s[i] != s[i-1]) 
                ans++;
        }
        return ans;
    }
};