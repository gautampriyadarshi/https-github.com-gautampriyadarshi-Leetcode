class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        if(blocks.size() == 1)
        {
            if(blocks[0] == 'W')
                return 1;
            else
                return 0;
        }

        int mini = INT_MAX, maxi = INT_MIN, countW = 0, countB = 0, countT = 0;
        bool present = false;
        for(int i = 0; i < blocks.size(); i++)
        {
            countT++;
            if(blocks[i] == 'W')
                countW++;
            
            if(blocks[i] == 'B')
                countB++;
            
            if(countT == k)
            {
                mini = min(mini, countW);
                if(blocks[i-k+1] == 'W')
                    countW--;
                
                maxi = max(maxi, countB);
                if(blocks[i-k+1] == 'B')
                    countB--;
                
                countT--;
            }
        }

        if(maxi == k)
            return 0;

        return mini;
    }
};