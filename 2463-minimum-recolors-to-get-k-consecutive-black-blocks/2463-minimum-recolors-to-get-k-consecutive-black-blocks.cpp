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

        int mini = INT_MAX, countW = 0, countT = 0;
        for(int i = 0; i < blocks.size(); i++)
        {
            countT++;
            if(blocks[i] == 'W')
                countW++;
            
            if(countT == k)
            {
                mini = min(mini, countW);
                if(blocks[i-k+1] == 'W')
                    countW--;
                
                countT--;
            }
        }
        return mini;
    }
};