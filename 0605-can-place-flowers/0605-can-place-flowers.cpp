class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count = n;

        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] != n)
                return true;
            
            if(flowerbed[0] == 0 && n == 0)
                return true;
            
            return false;
        }

        for(int i = 0; i < flowerbed.size(); i++)
        {
            if(count == 0)
                return true;
            
            if(i > 0 && i < flowerbed.size()-1)
            {
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
                {
                    flowerbed[i] = 1;
                    count--;
                }
            }
            else if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count--;
            }
            else if(i == flowerbed.size()-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)
            {
                flowerbed[i] = 1;
                count--;
            }
            
        }

        return count == 0;
    }
};