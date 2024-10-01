class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
			//to handle negative cases
            mp[( (arr[i] % k) + k) % k]++;
        }

        for(int i = 0; i < n; i++)
        {
            int rem1 = arr[i] % k;
            if(rem1 == 0)
            {
                if(mp[rem1] % 2 != 0) 
                    return false;
            }
            else
            {
                int rem2 = k - rem1;
                if(mp[rem1] != mp[rem2]) 
                    return false;
            }
        }
        return true;   
    }
};