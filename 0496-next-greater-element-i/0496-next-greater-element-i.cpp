class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        // Map to store: element -> its next greater element
        unordered_map<int, int> next_greater_map;
        stack<int> st;

        // Iterate through nums2 to find next greater elements for all its values
        for (int num : nums2) 
        {
            // While stack is not empty and 
            // current number is greater than the stack's top
            while (!st.empty() && num > st.top()) 
            {
                // The current 'num' is the next greater element for st.top()
                next_greater_map[st.top()] = num;
                st.pop();
            }

            // Push current number to find its next greater later
            st.push(num);
        }

        vector<int> ans;
        for (int num : nums1) 
        {
            // If the element exists in our map, use the mapped value, else -1
            if (next_greater_map.count(num)) 
                ans.push_back(next_greater_map[num]);
            else 
                ans.push_back(-1);
        }

        return ans;
    }
};

/*
Time Complexity (TC): O(N + M).
We traverse nums2 of length N once. 
Each element is pushed and popped from the stack exactly once (O(N)).
We then traverse nums1 of length M once (O(M)).
Total time is linear relative to the input size.

Space Complexity (SC): O(N)
In the worst case (a strictly decreasing array), 
the stack will store all N elements of nums2.
The unordered_map also stores up to N key-value pairs.
*/