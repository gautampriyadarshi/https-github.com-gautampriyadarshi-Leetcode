class Solution {
public:
    int numberOfChild(int n, int k) 
    {
        int ans = -1;
        bool right = true;

        while(k > 0)
        {
            if(right)
            {
                for(int i = 1; i < n; i++)
                {
                    if(i == n-1)
                    {
                        k--;
                        right = false;
                    }
                    else
                        k--;
                    
                    if(k == 0)
                        ans = i;
                }
            }
            else
            {
                for(int i = n-2; i >= 0; i--)
                {
                    if(i == 0)
                    {
                        k--;
                        right = true;
                    }
                    else
                        k--;
                    
                    if(k == 0)
                        ans = i;
                }
            }
        }
        return ans;
    }
};