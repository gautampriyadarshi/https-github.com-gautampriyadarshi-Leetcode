class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }

        if(arr.size() > 2)
        {
            int size = 3; 
            while(size <= arr.size())
            {
                int sum = 0;
                // Window:
                for(int i = 0; i < size; i++)
                {
                    sum += arr[i];
                }
                ans += sum;

                int j = 0;
                for(int i = size; i < arr.size(); i++)
                {
                    sum = sum - arr[j];
                    sum += arr[i];
                    j++;
                    ans += sum;
                }
                size += 2;
            }
        }
        else
            return ans;
        
        return ans;
    }
};