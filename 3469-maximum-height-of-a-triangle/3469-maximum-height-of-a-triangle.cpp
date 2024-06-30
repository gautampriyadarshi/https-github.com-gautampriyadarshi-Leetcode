class Solution {
public:
    int maxHeightOfTriangle(int r, int b) 
    {
        // int Rd = red, Bl = blue;
        // int i = 0, level = 1, balls = 0, maxi = INT_MIN;
        // while(balls <= red + blue)
        // {
        //     if(i % 2 != 0)
        //     {
        //         if(blue == 0)
        //             break;
                
        //         level++;
        //         if(blue - level >= 0)
        //         {
        //             blue = blue - level;
        //             balls += level;
        //             i++;
        //         }
        //         else
        //         {
        //             level--;
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         if(red == 0)
        //             break;
                
        //         level++;
        //         if(red - level >= 0)
        //         {
        //             red = red - level;
        //             balls += level;
        //             i++;
        //         }
        //         else
        //         {
        //             level--;
        //             break;
        //         }
        //     }
        // }

        // maxi = max(maxi, level);
        // i = 0, level = 1, balls = 0;
        // while(balls <= red + blue)
        // {
        //     if(i % 2 != 0)
        //     {
        //         if(Rd == 0)
        //             break;
                
        //         level++;
        //         if(Rd - level >= 0)
        //         {
        //             Rd = Rd - level;
        //             balls += level;
        //             i++;
        //         }
        //         else
        //         {
        //             level--;
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         if(Bl == 0)
        //             break;
                
        //         level++;
        //         if(Bl - level >= 0)
        //         {
        //             Bl = Bl - level;
        //             balls += level;
        //             i++;
        //         }
        //         else
        //         {
        //             level--;
        //             break;
        //         }
        //     }
        // }
        // maxi = max(maxi, level);

        // return maxi;

        int x = 0, c = 1, t = 0, red = r, blue = b;
        // first calculate for if the first ball is red
        while(red + blue >= c) {
            if(c % 2 == 0)
                if(blue >= c) blue -= c, c++, t++;
                else break;
            else
                if(red >= c) red -= c, c++, t++;
                else break;
        }
        x = max(x, t), c = 1, red = r, blue = b, t = 0;
        
        // calculate for if the first ball is blue
        while(red + blue >= c){
            if(c % 2 == 0) {
                if(red >= c) red -= c, c++, t++;
                else break;
            }
            else
            {   
                if(blue >= c) blue -= c, c++, t++;
                else break;
            }
                
        }
        return max(x, t);
    }
};