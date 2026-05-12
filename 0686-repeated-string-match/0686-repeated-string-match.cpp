class Solution {
private:
    // Step 1: Build the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(const string& pattern) 
    {
        int m = pattern.length();
        vector<int> lps(m, 0);
        
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;
        
        // Loop calculates lps[i] for i = 1 to m-1
        while (i < m) 
        {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else 
            { 
                if (len != 0) 
                    len = lps[len - 1];
                else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Step 2: Use the LPS array to search for the pattern in the text
    bool kmpSearch(const string& text, const string& pattern) 
    {
        int n = text.length(), m = pattern.length();
        
        if (m == 0) 
            return true;
        
        vector<int> lps = computeLPS(pattern);
        
        int i = 0; // index for text
        int j = 0; // index for pattern
        
        while (i < n) 
        {
            // If characters match, move both pointers forward
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            
            // If we've reached the end of the pattern, we found a match!
            if (j == m) 
                return true; 

            // Mismatch after at least one matching character
            else if (i < n && pattern[j] != text[i]) 
            {
                if (j != 0) 
                    j = lps[j - 1]; 
                else 
                    i++;
            }
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) 
    {
        int n = a.length(), m = b.length();
        
        // Calculate the minimum repetitions required
        // (m + n - 1) / n is a clean math trick for ceiling division: ceil(m/n)
        int minRepeats = (m + n - 1) / n; 
        
        // Build the baseline repeated string
        string repeatedA = "";
        for (int i = 0; i < minRepeats; i++) {
            repeatedA += a;
        }
        
        // 1st Check: Is 'b' inside the baseline string?
        if (kmpSearch(repeatedA, b)) 
            return minRepeats;
        
        // 2nd Check: The +1 Edge Case (wrap-around)
        repeatedA += a;
        if (kmpSearch(repeatedA, b)) 
            return minRepeats + 1;
        
        return -1;
    }
};

// TC: O(N+M)
// Building the LPS array for string b takes O(M) time. 
// The kmpSearch scans the built string (which is roughly N + M in length)  exactly once without ever moving the text pointer i backwards. 
// This takes O(N + M) time.

// SC: O(N+M)
// O(M) to store the lps array.
// O(N + M) to store the repeatedA string.