class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int n = chars.size(), count = 1, i = 1;
        string st = "", num = "";
        
        while(i < n)
        {
            if(chars[i] == chars[i-1])
                count++;
            else
            {
                num = to_string(count);
                
                if(count > 1)
                    st += chars[i-1] + num;
                else
                    st += chars[i-1];
                
                count = 1;
            }
            i++;
        }

        num = to_string(count);
        if(count > 1)
            st += chars[i-1] + num;
        else
            st += chars[i-1];

        n = st.size();
        chars.clear();

        for(int i = 0; i < n; i++) {
            chars.push_back(st[i]);
        }

        return n;
    }
};