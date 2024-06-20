class Solution {
    bool solve(vector<int> pos, int mid, int m)
    {
        int count = 1;
        int prev = pos[0];

        for(int i = 0; i < pos.size(); i++)
        {
            if(pos[i] - prev >= mid)
            {
                count++;
                prev = pos[i];

                if(count == m)
                    return true;
            }
        }

        if(count < m)
            return false;
        
        return true;
    }
public:
    int maxDistance(vector<int>& pos, int m) 
    {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        int ans = 0, low = 0, high = pos[n-1];

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(solve(pos, mid, m))
            {
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};