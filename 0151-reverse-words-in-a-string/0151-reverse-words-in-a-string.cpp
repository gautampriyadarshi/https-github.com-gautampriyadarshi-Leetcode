class Solution {
public:
    string reverseWords(string s) 
    {
        if(s.size() == 1)
            return s;

        vector<string> vec;
        string st = "", ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
                st += s[i];
            else
            {
                if(st == "")
                    continue;
                else
                {
                    vec.push_back(st);
                    st = "";
                }
            }
        }

        if(st != "")
            vec.push_back(st);
        
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < vec.size()-1; i++)
        {
            ans += vec[i] + " ";
        }
        ans += vec[vec.size()-1];
        vec.clear();
        
        return ans;
    }
};