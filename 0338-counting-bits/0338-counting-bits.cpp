class Solution {
    int count(string num)
    {
        int x = 0;
        for(int i = 0; i < num.size(); i++)
        {
            if(num[i] == '1')
                x++;
        }
        return x;
    }

    string binary(int num)
    {
        string help = "";
        while(num > 0)
        {
            int x = num % 2;
            help += to_string(x);
            num = num / 2;
        }
        return help;
    }
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans;
        ans.push_back(0);

        for(int i = 1; i <= n; i++)
        {
            string hp = binary(i);
            int num = count(hp);
            ans.push_back(num);
        }
        return ans;
    }
};