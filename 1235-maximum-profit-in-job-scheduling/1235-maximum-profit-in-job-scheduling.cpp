class Solution {
    int Rec(int ind, int n, vector<vector<int>>& jobs)
    {
        if (ind == n)
            return 0;
        
        // Move to the immediately next job in the sorted list
        int notTake = 0 + Rec(ind + 1, n, jobs);
        
        // Find the index of the next job that starts AFTER or exactly WHEN the current job ends
        int nextInd = n; 
        for (int i = ind + 1; i < n; i++) 
        {
            // startTime of new ind >= endTime of old ind
            if (jobs[i][0] >= jobs[ind][1]) {   
                nextInd = i;
                break;
            }
        }
        
        // Add the current job's profit and jump to the next valid job
        int take = jobs[ind][2] + Rec(nextInd, n, jobs);
        
        return max(take, notTake);
    }
    
    int Mem(int ind, int n, vector<vector<int>>& jobs, vector<int> &dp)
    {
        if (ind == n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int notTake = 0 + Mem(ind + 1, n, jobs, dp);
        
        int nextInd = n; 
        for (int i = ind + 1; i < n; i++) 
        {
            // startTime of new ind >= endTime of old ind
            if (jobs[i][0] >= jobs[ind][1]) {   
                nextInd = i;
                break;
            }
        }
        int take = jobs[ind][2] + Mem(nextInd, n, jobs, dp);
        
        return dp[ind] = max(take, notTake);
    }

    int Tab(int n, vector<vector<int>>& jobs)
    {
        vector<int> dp(n+1, 0); // Base Case

        for(int ind = n - 1; ind >= 0; ind--)
        {
            int notTake = 0 + dp[ind + 1];
            int nextInd = n; 
            int low = ind + 1;
            int high = n - 1;
            
            while (low <= high) 
            {
                int mid = low + (high - low) / 2;
                
                // If the job at 'mid' starts after or when the current job ends
                if (jobs[mid][0] >= jobs[ind][1]) {
                    nextInd = mid;   // Valid! Save it.
                    high = mid - 1;  // Look left for an even earlier valid job
                } 
                else
                    low = mid + 1;   // Starts too early, look right
            }
            int take = jobs[ind][2] + dp[nextInd];
            dp[ind] = max(take, notTake);
        }
        return dp[0];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = profit.size();
        
        // Step 1: Bundle the arrays together so we can sort them
        vector<vector<int>> jobs(n, vector<int>(3));    // (n x 3 matrix)
        for(int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        // Step 2: Sort the jobs based on startTime
        sort(jobs.begin(), jobs.end());
        
        // Recursion:
        // return Rec(0, n, jobs);

        // Memoization:
        // vector<int> dp(n, -1);
        // return Mem(0, n, jobs, dp);

        // Tabulation
        return Tab(n, jobs);
    }
};