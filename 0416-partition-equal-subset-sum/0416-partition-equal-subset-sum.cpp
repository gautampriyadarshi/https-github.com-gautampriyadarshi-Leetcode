class Solution {
    bool Rec(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;

    if (ind == 0)
    {
        if (arr[0] == target)
            return true;

        return false;
    }

    bool notTake = Rec(ind - 1, target, arr);
    bool take = false;

    if (arr[ind] <= target)
        take = Rec(ind - 1, target - arr[ind], arr);

    return (take || notTake);
}

bool Mem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
    {
        if (arr[0] == target)
            return true;

        return false;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = Mem(ind - 1, target, arr, dp);
    bool take = false;

    if (arr[ind] <= target)
        take = Mem(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (take || notTake);
}

bool Tab(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;

            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

public:
    bool canPartition(vector<int>& arr) 
    {
        int sum = 0, k = 0, n = arr.size();
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if(sum % 2 != 0)
            return false;

        k = sum/2;

        // Recursion:
        // return Rec(n - 1, k, arr);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return Mem(n - 1, k, arr, dp);

        // Tabulation: Little bit indexing error here, but process is correct.
        // return Tab(n, k, arr);
    }
};