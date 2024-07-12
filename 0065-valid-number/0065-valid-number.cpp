class Solution {
public:
    bool isNumber(string s) 
    {
        // Wrong answer: 1418/1494 cases passes:
    /*  if(s.size() == 1)
        {
            if(s[0] == 'e' || s[0] == '.' || s[0] == '-' || s[0] == '+')
                return false;
        }

        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i] == '-' || s[i] == 'E' || s[i] == 'e' || s[i] == '.')
            {
                if(mp[s[i]] > 0)
                    return false;
                
                mp[s[i]]++;
            }

            if(s[i] >= 'a' && s[i] <= 'z' && s[i] != 'e')
                return false;
            
            if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'E')
                return false;

            if(i != 0)
            {
                if((s[i] == '+' && s[i-1] == '-') || (s[i] == '-' && s[i-1] == '-') || 
                (s[i] == '-' && s[i-1] == '+') || (s[i] == '+' && s[i-1] == '+'))
                    return false;
            }

            if((i == 0 || i == s.size()-1) && s[i] == 'e')
                return false;
        }
        return true;    */

        int i=0, n=s.size();

        // iterate over sign
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;
        
        bool beforeInt = false;

        // iterating digits
        while(s[i]>='0' && s[i]<='9' && i<n){
            i++;
            beforeInt = true;
        }

        // checking ending condition
        if(i>=n) return true;

        // Passing dot
        bool dot = false;
        if(s[i] == '.') {i++; dot = true;}

        // check dot ending condition
        if(i>=n)
            if(dot==true && beforeInt==false) return false;
            else return true;
        
        // bool afterInt = false;

        // check digit after dot
        if(dot) 
        if(beforeInt) {if((s[i]<'0' || s[i]>'9') && (s[i]!='e' && s[i]!='E') ) return false; }
        else {if(s[i]<'0' || s[i]>'9') return false; }

        // iterate decimals until we reach last indext or e
        while(i<n && s[i]!='e' && s[i]!='E'){
            if(s[i]<'0' || s[i]>'9') return false;
            i++;
        }
        if(!dot)
        if((s[i]=='e' || s[i]=='E') && beforeInt==false) return false;
        // checking ending condition
        if(i>=n) return true;
        
        i++; // next ot e
        
        // iterate sign
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;

        bool lastInt = false;
        // iterate over digits
        while(s[i]>='0' && s[i]<='9' && i<n){
            i++;
            lastInt = true;
        }

        if(!lastInt) return false;

        if(i>=n) return true;
        return false;
    }
};