class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i < gain.size(); i++)
        {
            sum += gain[i];
            maxi = max(maxi, sum);
        }

        if(maxi < 0)
            return 0;
            
        return maxi;
    }
};