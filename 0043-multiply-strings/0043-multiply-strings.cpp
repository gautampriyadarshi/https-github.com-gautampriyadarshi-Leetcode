class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        string help1 = "";
        string help2 = "";

        if(num1[0] == '-' )
        {
            help1 = "-";
            num1 = num1.substr(1);
        }

        if(num2[0] == '-' )
        {
            help2 = "-";
            num2 = num2.substr(1);
        }

        if(help1 == "-" && help2 == "-")
        {
            help1 = help2 = "";
        }

        int n = num1.size();
        int m = num2.size();
        string res(n+m,'0');
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                int num = (num1[i] - '0') * (num2[j] - '0') + (res[i+j+1] - '0');
                res[i+j+1] = num % 10 + '0';
                res[i+j] += num / 10; // carry
            }
        }

        int i=0;
        while(i < res.size() && res[i] == '0') 
            i++;

        return help1 + help2 + res.substr(i);
    }
};