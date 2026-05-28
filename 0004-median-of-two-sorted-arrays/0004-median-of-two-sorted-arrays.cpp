class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) 
    {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        vector<double> num(m+n, -1);
        
        for(int x = 0; x < m+n; x++)
        {
            if(i < m && j < n)
            {
                if(a[i] < b[j])
                    num[x] = a[i++];
                else
                    num[x] = b[j++];
            }
            else
            {
                if(i < m)
                    num[x] = a[i++];
                else
                    num[x] = b[j++];
            }
        }
        
        if((m+n) % 2 != 0)
            return num[(m+n)/2];
        
        return (num[(m+n)/2] + num[((m+n)/2)-1])/2;
    }
};