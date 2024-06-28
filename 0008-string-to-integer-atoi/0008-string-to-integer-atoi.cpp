class Solution {
public:
    int myAtoi(string s) 
    {
        // My code: 1001/1094 cases passed after too much debugging.
        /*
        string num = "";
        bool sub = false;
        long long x = 0;
        int y = -1;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            else if(s[i] == '-')
            {
                if(i == 0)
                {
                    sub = true;
                    x = i;
                    break;
                }

                if(i != 0 && s[i-1] == ' ')
                {
                    sub = true;
                    x = i;
                    break;
                }
            }
            else if(s[i] == '+')
                y = i;
        }

        if(sub)
        {
            for(int i = x + 1; i < s.size(); i++)
            {
                // if(s[x+1] == '0')
                //     continue;
                
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '.') || (s[i] == '-') || (s[i] == '+'))
                    break;
                
                if(s[i] >= '0' && s[i] <= '9')
                {
                    if(num == "" && s[i] == '0')
                        continue;
                    else
                        num += s[i];
                }
                //cout << num << " ";
            }
            
        }
        else
        {
            if(y == -1)
            {
                for(int i = 0; i < s.size(); i++)
                {
                    // if(s[0] == '0')
                    //     continue;

                    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '.') || (s[i] == '-') || (s[i] == '+'))
                        break;

                    if(s[i] >= '0' && s[i] <= '9')
                    {
                        if(num == "" && s[i] == '0')
                            continue;
                        else
                            num += s[i];
                    }
                }
            }
            else
            {
                for(int i = y+1; i < s.size(); i++)
                {
                    // if(s[0] == '0')
                    //     continue;

                    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '.') || (s[i] == '-') || (s[i] == '+'))
                        break;

                    if(s[i] >= '0' && s[i] <= '9')
                    {
                        if(num == "" && s[i] == '0')
                            continue;
                        else
                            num += s[i];
                    }
                }
            }
        }

        if(num == "")
            return 0;
        
        if(num < "-2147483648")
            return INT_MIN;

        //cout << num;
        int ans = 0, i = 0;
        x = 1;
        reverse(num.begin(), num.end());
        while(i < num.size())
        {
            int p = num[i] - '0';
            ans = ans + x * p;

            if(x * 10 > INT_MAX)
            {
                if(sub)
                    return INT_MIN;
                
                return INT_MAX;
            }
            x *= 10;
            i++;
        }
        
        if(sub)
            ans = ans * (-1);

        return ans; */

        int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                i++;
            }
            else
                return ans*sign;
        }
        return (ans*sign);
    }
};