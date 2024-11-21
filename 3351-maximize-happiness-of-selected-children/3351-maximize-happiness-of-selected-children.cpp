class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) 
    {
        sort(hap.begin(),hap.end());
        long long sum = 0;
        int sub = 0, n = hap.size();
        
        for(int i = n-1; i >= 0; i--)
        {
            if(k == 0) 
                break;

            int val = hap[i]-sub;
            if(val > 0) 
                sum += val;

            sub++;
            k--;
        }
        return sum;
        
        
    }
};