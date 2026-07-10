// Memoization will fail as we don't know below:
// vector<vector<int>> dp(size, vector<int>( /* ??? */ , -1));
class Solution {
public:
    int minimumDifference(vector<int>& nums) 
    {
        int size = nums.size();
        int n = size / 2;
        long long totalSum = 0;
        
        for (int i = 0; i < size; i++) {
            totalSum += nums[i];
        }
        
        // These arrays of vectors will store our subset sums.
        // left_sums[k] will store all possible sums we can make by picking EXACTLY k elements from the left half.
        // right_sums[k] will store all possible sums we can make by picking EXACTLY k elements from the right half.
        vector<vector<long long>> left_sums(n + 1);
        vector<vector<long long>> right_sums(n + 1);
        
        // 1 << n is 2^n. For n=15, this loop runs 32,768 times. Very fast!
        for (int mask = 0; mask < (1 << n); mask++) {
            int elementsPicked = 0;
            long long currentLeftSum = 0;
            long long currentRightSum = 0;
            
            for (int i = 0; i < n; i++) {
                // Check if the i-th bit is set in our mask
                if (mask & (1 << i)) {
                    elementsPicked++;
                    currentLeftSum += nums[i];        // Picked from (indices 0 to n-1)
                    currentRightSum += nums[i + n];   // Picked from (indices n to 2n-1)
                }
            }
            
            // Save the sums in their respective buckets based on how many elements were picked
            left_sums[elementsPicked].push_back(currentLeftSum);
            right_sums[elementsPicked].push_back(currentRightSum);
        }
        
        // We only need to sort the right half so we can use lower_bound on it.
        for (int i = 0; i <= n; i++) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }
        
        long long minDifference = LLONG_MAX;
        
        // We want our subset of size 'n' to have a sum as close to (totalSum / 2) as possible.
        long long idealTarget = totalSum / 2;
        
        // Let's say we pick 'k' elements from the Left half...
        for (int k = 0; k <= n; k++) {
            // ... then we MUST pick 'n - k' elements from the Right half.
            int rightElementsNeeded = n - k;
            
            // For every sum we generated in the Left half with 'k' elements:
            for (long long leftSum : left_sums[k]) {
                
                // We want: leftSum + rightSum ≈ idealTarget
                // So, rightSum ≈ idealTarget - leftSum
                long long neededRightSum = idealTarget - leftSum;
                
                // Use binary search to find the closest actual rightSum we generated
                auto& rightBucket = right_sums[rightElementsNeeded];
                auto it = lower_bound(rightBucket.begin(), rightBucket.end(), neededRightSum);
                
                // Case 1: The iterator points to an element >= neededRightSum
                if (it != rightBucket.end()) {
                    long long rightSum = *it;
                    long long subset1_Sum = leftSum + rightSum;
                    long long subset2_Sum = totalSum - subset1_Sum;
                    minDifference = min(minDifference, abs(subset1_Sum - subset2_Sum));
                }
                
                // Case 2: The element just BEFORE the iterator might be closer (<= neededRightSum)
                if (it != rightBucket.begin()) {
                    auto prev_it = prev(it);
                    long long rightSum = *prev_it;
                    long long subset1_Sum = leftSum + rightSum;
                    long long subset2_Sum = totalSum - subset1_Sum;
                    minDifference = min(minDifference, abs(subset1_Sum - subset2_Sum));
                }
            }
        }
        
        return minDifference;
    }
};