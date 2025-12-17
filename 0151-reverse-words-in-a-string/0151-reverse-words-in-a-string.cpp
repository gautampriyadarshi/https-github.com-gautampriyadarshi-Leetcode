class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string> vec;
        string help = "", x = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
                help += s[i];
            else
            {
                if(help == "")
                    continue;
                else
                {
                    vec.push_back(help);
                    help = "";
                }
            }
        }

        if(help != "")
            vec.push_back(help);

        reverse(vec.begin(), vec.end());

        for(int i = 0; i < vec.size(); i++)
        {
            if(i != vec.size()-1)
                x += vec[i] + " ";
            else
                x += vec[i];
        }
        vec.clear();
        
        return x;
    }
};