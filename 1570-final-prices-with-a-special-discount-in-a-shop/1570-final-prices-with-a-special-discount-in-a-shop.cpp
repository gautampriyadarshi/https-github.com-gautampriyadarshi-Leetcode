class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int> vec;
        for(int i = 0; i < prices.size(); i++)
        {
            int size = vec.size();
            for(int j = i+1; j < prices.size(); j++)
            {
                if(prices[j] <= prices[i])
                {
                    vec.push_back(prices[i]-prices[j]);
                    break;
                }
                    
            }

            if(vec.size() == size)
                vec.push_back(prices[i]);
        }
        return vec;
    }
};