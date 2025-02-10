class Solution {
public:
    string clearDigits(string s) 
    {
        string ans = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            st.push(s[i]);
        }

        bool pr = false;
        int count = 0;
        while(!st.empty())
        {
            if(st.top() >= '0' && st.top() <= '9')
            {
                st.pop();
                count++;
            }  
            
            if(count > 0)
            {
                while(count > 0)
                {
                    if(st.top() >= 'a' && st.top() <= 'z')
                    {
                        st.pop();
                        count--;
                    }
                    else
                        break;
                }
            }
            else
            {
                char tp = st.top();
                st.pop();
                ans += tp;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};