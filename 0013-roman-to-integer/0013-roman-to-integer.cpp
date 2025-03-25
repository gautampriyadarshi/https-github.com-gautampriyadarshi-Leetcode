class Solution {
public:
    int romanToInt(string s) 
    {
        int n = s.length(), sum = 0, i;
        for(i = 0; i < n; i++)
        {
            char c = s[i];
            switch(c)
            {
                case 'I':
                {
                    if(s[i+1] == 'V')
                    {
                        sum += 4;
                        i++;
                        break;
                    }
                    else if(s[i+1] == 'X')
                    {
                        sum += 9;
                        i++;
                        break;
                    }
                    else
                    {
                        sum++;
                        break;
                    }
                } 
                case 'X':
                {
                    if(s[i+1] == 'L')
                    {
                        sum += 40;
                        i++;
                        break;
                    }
                    else if(s[i+1] == 'C')
                    {
                        sum += 90;
                        i++;
                        break;
                    }
                    else
                    {
                        sum += 10;
                        break;
                    }
                }
                case 'C':
                {
                    if(s[i+1] == 'D')
                    {
                        sum += 400;
                        i++;
                        break;
                    }
                    else if(s[i+1] == 'M')
                    {
                        sum += 900;
                        i++;
                        break;
                    }
                    else
                    {
                        sum += 100;
                        break;
                    }
                }
                case 'V':
                {
                    sum += 5;
                    break;
                }
                case 'L':
                {
                    sum += 50;
                    break;
                }
                case 'D':
                {
                    sum += 500;
                    break;
                }
                case 'M':
                {
                    sum += 1000;
                    break;
                }
            }
        }
        return sum;
    }
};