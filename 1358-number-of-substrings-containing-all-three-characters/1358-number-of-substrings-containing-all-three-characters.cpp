class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        if(s.size() < 3)
            return 0;
        
        int count = 0, left = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        for (int right = 0; right < s.length(); ++right) 
        {
            char_count[s[right]]++;
            
            while (char_count['a'] > 0 && char_count['b'] > 0 && 
                    char_count['c'] > 0) 
            {
                count += s.length() - right; // --> See below notes for explanation
                char_count[s[left]]--;
                left++;
            }
        }
        return count;
    }
};

/******* Line: 18 explanation

1. Finding the first valid window:
Your right pointer moves from index 0 to 2.
At index 2, your window is s[0...2] which is "abc".
left = 0
right = 2

You have one 'a', one 'b', and one 'c'. The while loop triggers!

2. The Math (count += s.length() - right;)
You plug the numbers into your formula: 6 - 2 = 4.
Your code just added 4 valid substrings to the count. But what exactly are those 4 substrings?

Since the core window "abc" (from index 0 to 2) is valid, we know these combinations are guaranteed to be valid:

s[0...2] -> "abc"
s[0...3] -> "abca" (extends 1 character)
s[0...4] -> "abcab" (extends 2 characters)
s[0...5] -> "abcabc" (extends 3 characters)

By taking the total length (6) and subtracting the index where the window became valid (2), it perfectly calculates the current valid window plus all the extra trailing characters left in the string!

3. Shrinking the window:
After adding those 4 to your count, your code does left++. It drops the 'a' at index 0, the window becomes invalid, and your for loop resumes moving right to find the next valid block. i.e. just to come out of while loop doing this.

*******/