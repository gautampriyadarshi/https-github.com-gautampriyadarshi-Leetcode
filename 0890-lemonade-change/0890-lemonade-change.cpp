class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        if(bills.size() == 1)
        {
            if(bills[0] == 5)
                return true;
            else
                return false;
        }

        int count5 = 0, count10 = 0;
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
                count5++;
            else if(bills[i] == 10)
            {
                count10++;
                if(count5 == 0)
                    return false;

                count5--;
            }
            else if(bills[i] == 20)
            {
                if(count10 == 0 && count5 == 0)
                    return false;
                else if(count5 < 3 && count10 == 0)
                    return false;
                
                if(count10 > 0)
                {
                    count10--;
                    if(count5 >= 1)
                        count5--;
                    else
                        return false;
                }
                else
                {
                    if(count5 >= 3)
                        count5 = count5-3;
                    else
                        return false;

                }    
            }
        }
        return true;
    }
};