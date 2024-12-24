class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time = 0;
        for(int i = 0; i < tickets.size(); i++)
        {
            if(tickets[k] == 0)
                break;
            
            if(tickets[i] != 0)
            {
                tickets[i]--;
                time++;
            }

            if(i == tickets.size()-1)
            {
                if (tickets[k] != 0) 
                    i =- 1 ;
            }
        }
        return time;
    }
};