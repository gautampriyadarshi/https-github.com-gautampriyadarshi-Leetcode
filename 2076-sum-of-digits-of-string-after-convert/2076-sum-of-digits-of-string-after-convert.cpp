class Solution {
    int sum(string &num, int k)
    {
        int ans = 0;
        while(k > 0)
        {
            int x = 0;
            for(int i = 0; i < num.size(); i++)
            {
                x += (num[i] - '0');
            }

            num = to_string(x);
            ans = x;
            k--;
        }
        return ans;
    }
public:
    int getLucky(string s, int k) 
    {
        string num = "";
        for(int i = 0; i < s.size(); i++)
        {
            int x = (int)s[i] - 96;
            num += to_string(x);
        }
        return sum(num, k);
    }
};