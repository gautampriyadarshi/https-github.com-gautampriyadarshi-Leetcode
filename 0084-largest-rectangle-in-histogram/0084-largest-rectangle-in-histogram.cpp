//Time: O(n), because every index is pushed and popped from the stack exactly once.

// Space: O(n) for the stack in the worst-case scenario 
//        (e.g., heights are in increasing order).

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> s; // Stores indices of the bars
        int maxArea = 0;

        for (int i = 0; i <= n; i++) 
        {
            // Use 0 height for the 'extra' bar at the end to flush the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            // If the current bar is shorter than the bar at stack top,
            // the bar at stack top has found its right boundary.
            while (!s.empty() && currentHeight < heights[s.top()]) 
            {
                int h = heights[s.top()];
                s.pop();

                // Width is determined by the current index (right boundary)
                // and the index of the bar now at the top of the stack 
                // (left boundary).
                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            s.push(i);
        }
        return maxArea;
    }
};