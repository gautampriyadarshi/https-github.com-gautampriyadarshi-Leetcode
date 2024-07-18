class Solution {
public:
    int divisorSubstrings(int num, int k) 
    {
        int count = 0, j = 1;
        string given = to_string(num);
        string help = given.substr(0, k);
        int x = stoi(help);
        
        if(num % x == 0)
            count++;
        
        for(int i = k; i < given.size(); i++)
        {
            help = given.substr(j, k);
            x = stoi(help);

            if(help[0] == 0)
                continue;

            if(x != 0 && num % x == 0)
                count++;
            
            j++;
        }
        return count;
    }
};