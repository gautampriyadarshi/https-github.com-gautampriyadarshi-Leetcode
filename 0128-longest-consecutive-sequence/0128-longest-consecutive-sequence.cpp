class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) 
            return 0; 
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i = 0; i < nums.size(); i++) 
        {
            pq.push(nums[i]);
        }
        
        long long prev = pq.top();
        pq.pop();
        
        int maxi = 1;
        int count = 1;
        
        while(!pq.empty()) 
        {
            long long tp = pq.top();
            pq.pop();

            if (tp == prev) 
                continue;   // Ignore duplicates entirely
            else if (tp - prev == 1) 
            {
                count++;
                maxi = max(maxi, count);
            } 
            else 
                count = 1;  // Streak broken, reset count

            prev = tp;
        }
        return maxi;
    }
};