class Solution {
    int rev(vector<int>& a,vector<int>& b)
    {
        int count = 0, i = 0, j = 0;

        while(i < a.size() && j < b.size())
        {
            if((long long)a[i] > (long long)2*b[j])
            {
                count += a.size()-i;
                j++;
            }
            else 
                i++;
        }
        return count;
    }

    void marge(vector<int>& a, vector<int>& b, vector<int>& nums)
    {
        int i = 0, j = 0, k = 0;
        while(i < a.size() && j < b.size())
        {
            if(a[i] < b[j]) 
            {
                nums[k] = a[i];
                i++;
                k++;
            }
            else
            {
                nums[k] = b[j];
                j++;
                k++;
            }
        }

        if(i == a.size())
        {
            while(j < b.size())
            {
                nums[k] = b[j];
                j++;
                k++;
            }
        }
        
        if(j == b.size())
        {
            while(i < a.size())
            {
                nums[k] = a[i];
                i++;
                k++;
            }
        }
    }

    int merge(vector<int>& nums)
    {
        if(nums.size() == 1) 
            return 0;

        int n = nums.size(), count = 0;
        int n1 = n/2, n2 = n-n/2;
        vector<int> a(n1), b(n2);
        
        for(int i = 0; i < n1; i++) {
            a[i] = nums[i];
        }

        for(int i = 0; i < n2; i++) {
            b[i] = nums[i + n1];
        }

        count += merge(a);
        count += merge(b);
        count += rev(a,b);
        marge(a,b,nums);

        return count;
    }
public:
    int reversePairs(vector<int>& nums) 
    {
        return merge(nums);
    }
};