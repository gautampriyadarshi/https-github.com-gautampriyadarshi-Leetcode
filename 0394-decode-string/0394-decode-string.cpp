class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> st;
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] != ']') 
            {
                // Push characters/digits/open brackets as string tokens
                st.push(string(1, s[i]));
            } 
            else 
            {
                // 1. Pop everything until the matching '[' to get the inner string
                string innerStr = "";
                while (!st.empty() && st.top() != "[") 
                {
                    innerStr = st.top() + innerStr; // Prepend to preserve correct order
                    st.pop();
                }

                st.pop(); // Pop the '['

                // 2. Extract the complete number preceding '['
                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0])) 
                {
                    numStr = st.top() + numStr; // Prepend to handle multi-digit numbers (e.g. 100)
                    st.pop();
                }

                int k = stoi(numStr);

                // 3. Repeat innerStr k times
                string expanded = "";
                while (k > 0) 
                {
                    expanded += innerStr;
                    k--;
                }

                // 4. Push the expanded string BACK onto the stack
                // This allows outer nested brackets to use it!
                st.push(expanded);
            }
        }

        // Combine whatever is left in the stack into the final answer
        string ans = "";
        while (!st.empty()) 
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};