class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long long sum = 0, x = 0, y = 0;
        for(int i = 0; i < chalk.size(); i++)
        {
            sum += chalk[i];
        }

        if(k % sum == 0)
            return 0;
        
        x = sum;
        sum = k % sum;
        y = k / x;
        k = k - y * x;

        int ind = -1;
        cout << k;
        for(int i = 0; i < chalk.size(); i++)
        {
            if(k - chalk[i] < 0)
            {
                ind = i;
                break;
            }
            k = k - chalk[i];
        }
        return ind;
    }
};