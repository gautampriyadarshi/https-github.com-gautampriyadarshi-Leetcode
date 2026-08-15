class Solution {
    int Rec(int k, int n) 
    {
        // Base Case 1: If there are 0 floors, it takes 0 moves.
        // If there is 1 floor, it takes 1 move to test it.
        if (n == 0 || n == 1) 
            return n;
        
        // Base Case 2: If we only have 1 egg left, we must test every floor 
        // one by one from the bottom up to guarantee we find the floor.
        // So it will take 'n' moves.
        if (k == 1)
            return n;

        int minMoves = INT_MAX;

        // Try dropping an egg from every floor 'x' from 1 to n
        for (int x = 1; x <= n; x++) 
        {
            // If the egg breaks, we look at the (x-1) floors below with (k-1) eggs
            int broken = Rec(k - 1, x - 1);
            
            // If the egg survives, we look at the (n-x) floors above with k eggs
            int notBroken = Rec(k, n - x);
            
            // The worst-case scenario between breaking and not breaking
            int worstCaseForX = 1 + max(broken, notBroken);
            
            // We want to minimize our worst-case attempts across all choices of 'x'
            minMoves = min(minMoves, worstCaseForX);
        }
        
        return minMoves;
    }
    
    int Mem(int k, int n, vector<vector<int>> &dp) 
    {
        if (n == 0 || n == 1) 
            return n;
        
        if (k == 1)
            return n;
        
        if(dp[k][n] != -1)
            return dp[k][n];

        int minMoves = INT_MAX;

        // Binary Search instead of a linear for loop, else will give TLE
        int low = 1, high = n;
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            
            int broken = Mem(k - 1, mid - 1, dp);
            int notBroken = Mem(k, n - mid, dp);
            
            // The worst-case for dropping from floor 'mid'
            int worstCaseForMid = 1 + max(broken, notBroken);
            minMoves = min(minMoves, worstCaseForMid);
            
            if (broken < notBroken) {
                low = mid + 1;  // We must move our drop point higher up.
            }   
            else if (broken > notBroken) {
                high = mid - 1; // We must move our drop point lower down.
            } 
            else {
                break;  // Perfect balance point, no need to search further.
            }   
        }
        return dp[k][n] = minMoves;
    }
public:
    int superEggDrop(int k, int n) 
    {
        // Recursion:
        // return Rec(k, n);

        // Memoization:
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return Mem(k, n, dp);
    }
};