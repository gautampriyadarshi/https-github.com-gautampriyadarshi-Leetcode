class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) 
    {
        long long int sum = 0;
        sort(a.begin(), a.end());
        
        for(int i = 0; i < a.size(); i++)
        {
            if(k > 0 && a[i] < 0)
            {
                a[i] = (-1) * a[i];
                sum += a[i];
                k--;
            }
            else
                sum += a[i];
        }

        sort(a.begin(), a.end());

        if(k % 2 != 0)
            sum -= 2*a[0];

        return sum;
    }
};