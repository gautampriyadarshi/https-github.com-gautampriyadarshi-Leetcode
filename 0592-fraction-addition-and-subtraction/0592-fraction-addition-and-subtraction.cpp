class Solution {
    int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        
        return gcd(b, a % b);
    }
public:
    string fractionAddition(string expression) 
    {
        if(expression == "-1/1")
            return expression;
            
        vector<string> num, deno;
        bool nu = true, den = false;
        string help = "";

        int x = 0;
        while(expression[x] != '/')
        {
            help += expression[x];
            x++;
        }

        for(int i = x; i < expression.size(); i++)
        {
            if(nu)
            {
                if(expression[i] == '/')
                {
                    num.push_back(help);
                    help = "";
                    nu = false;
                    den = true;
                }
                else
                    help += expression[i];
            }
            else if(den)
            {
                if(expression[i] == '+' || expression[i] == '-')
                {
                    deno.push_back(help);
                    help = "";

                    if(expression[i] == '-')
                        help += expression[i];

                    den = false;
                    nu = true;
                }
                else
                    help += expression[i];
            }

            if(i == expression.size()-1)
                deno.push_back(help);
        }

        int maxi = INT_MIN;
        for(int i = 0; i < deno.size(); i++)
        {
            int d = stoi(deno[i]);
            maxi = max(maxi, d);
        }

        // Finding LCM:
        for(int i = 0; i < deno.size(); i++)
        {
            int p = stoi(deno[i]);
            p = (p / gcd(p, maxi)) * maxi;
            maxi = max(maxi, p);
        }

        // Making denominator equal and solving for num:
        for(int i = 0; i < deno.size(); i++)
        {
            int p = stoi(deno[i]);
            int div = maxi / p;
            deno[i] = to_string(maxi);

            int m = stoi(num[i]);
            m *= div;
            num[i] = to_string(m);
        }


        int num_sum = 0;
        for(int i = 0; i < num.size(); i++)
        {
            bool neg = false;
            int x;

            if(num[i][0] == '-')
                neg = true;
            
            if(neg)
            {
                string st = num[i].substr(1, num[i].size()-1);
                x = stoi(st);
                x = -x;
            }
            else
                x = stoi(num[i]);

            num_sum += x;
        }
        cout << num_sum;

        if(num_sum == 0)
            return "0/1";
        
        if(maxi != num_sum)
        {
            int sl = gcd(maxi, num_sum);
            maxi /= sl;
            num_sum /= sl;
        }
        
        string up = to_string(num_sum);
        string don = to_string(maxi);
        string dd = "";

        if(don[0] == '-')
        {
            up = '-' + up;
            dd = don.substr(1, don.size()-1);
        }

        if(up == don)
            return "1/1";

        if(dd == "")
            return (up + "/" + don);
        
        return (up + "/" + dd);
    }
};