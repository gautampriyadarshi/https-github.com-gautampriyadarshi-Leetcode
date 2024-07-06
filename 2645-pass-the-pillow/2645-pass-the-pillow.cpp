class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int count = 0, x = -1;
        bool leftToRight = true;
        while(count <= time)
        {
            if(leftToRight == true)
            {
                for(int i = 1; count <= time && i < n; i++)
                {
                    count++;
                    //cout << count << " ";
                    if(count > time)
                    {
                        x = i;
                        break;
                    }
                }
                leftToRight = false;
            }
            
            if(leftToRight == false)
            {
                for(int i = n; count <= time && i > 1; i--)
                {
                    count++;
                    //cout << count << " ";
                    if(count > time)
                    {
                        x = i;
                        break;
                    }
                }
                leftToRight = true;
            }

            if(x != -1)
                break;
        }
        return x;
    }
};