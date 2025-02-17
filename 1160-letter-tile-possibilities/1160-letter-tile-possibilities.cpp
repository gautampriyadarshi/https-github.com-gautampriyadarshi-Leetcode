class Solution
{
    // Step 1: Backtracking function
    int backtrack(unordered_map<char, int>& freqMap)
    {
        int count = 0;

        // Step 2: Iterate through each character in the frequency map
        for (auto& entry : freqMap)
        {
            if (entry.second > 0)
            {
                // Step 3: Pick a letter
                entry.second--;  // Reduce the frequency
                count += 1 + backtrack(freqMap);  // Recursive call
                
                // Step 4: Backtrack (restore count)
                entry.second++;
            }
        }

        return count;
    }
public:
    // Step 5: Main function to compute tile possibilities
    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> freqMap;

        // Step 6: Build frequency map
        for (char ch : tiles)
        {
            freqMap[ch]++;
        }

        // Step 7: Call backtracking function
        return backtrack(freqMap);
    }
};