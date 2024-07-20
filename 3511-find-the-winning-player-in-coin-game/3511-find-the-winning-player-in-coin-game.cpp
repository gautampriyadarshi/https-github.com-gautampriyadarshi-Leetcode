class Solution {
public:
    string losingPlayer(int x, int y) 
    {
        int i = 0, count = 0;
        while(x >= 1 && y >= 4)
        {
            if(i % 2 == 0) // Alice
            {
                x--;
                y = y-4;
                i++;
                count++;
            }
            else
            {
                x--;
                y = y-4;
                i++;
                count++;
            }
        }

        if(count % 2 != 0)
            return "Alice";
        
        return "Bob";
    }
};