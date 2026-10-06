class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int sz = flowerbed.size();

        for (int i = 0; i < sz; i++) 
        {
            if (n <= 0) 
                return true;

            if (flowerbed[i] == 0) 
            {
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == sz - 1 || flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) 
                {
                    flowerbed[i] = 1; // Greedily place the flower
                    n--;
                }
            }
        }

        return n <= 0;
    }
};