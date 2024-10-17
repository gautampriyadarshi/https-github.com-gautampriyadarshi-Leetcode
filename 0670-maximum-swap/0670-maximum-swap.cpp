class Solution {
public:
    int maximumSwap(int num) 
    {
        string x = to_string(num);
        int j = -1;
        for(int i = 0; i < x.size(); i++)
        {
            char maxi = x[i];
            for(int k = x.size()-1; k >= i+1; k--)
            {
                if(x[k] > maxi)
                {
                    maxi = x[k];
                    j = k;
                }
            }

            if(maxi != x[i])
            {
                swap(x[i], x[j]);
                break;
            }
        }
        return stoi(x); 
    }
};