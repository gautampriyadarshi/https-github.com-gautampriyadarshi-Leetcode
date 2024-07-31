class Solution {
public:
    string baseNeg2(int num) 
    {
        if(num == 0)
            return "0";

        string help = "";
        while(num)
        {
            if(num % 2 == 0)
                help += "0";
            else
                help += "1";
            
            num = - (num >> 1);    // Impt.
        }
        reverse(help.begin(), help.end());
        return help;
    }
};