class Solution {
public:
    string reorganizeString(string s) 
    {
        bool flag = true;  
        unordered_map<char,int> mp;
        
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;

            if(mp[s[i]] > 1)
                flag = false;
        }  
        
        if(flag == true)
            return s;		
          
        priority_queue<pair<int,char>>pq;
        
        for(auto it = mp.begin() ; it != mp.end() ; it++)
        {
            pq.push(make_pair(it->second,it->first)); 
        }
        
        string ans = "";
        while(!pq.empty())
        {
            if(ans.length() == 0)
            {
                pair<int,char>p = pq.top();
                pq.pop();
                
                ans.push_back(p.second);
                p.first--;
                
                if(p.first > 0 and pq.size() ==0)
                    return "";	
                
                pq.push(p);
            }
            
            else if(ans.length() > 0)
            {
                char lastchar = ans[ans.length()-1];
                
                pair<int,char>p1 = pq.top();
                pq.pop();
                
                if(p1.second == lastchar)
                {
                    if(pq.size()==0) return "";
                    
                    pair<int,char>p2 = pq.top();
                    pq.pop();
                    
                    ans.push_back(p2.second);
                    p2.first--;
                    
                    if(p2.first > 0)
                    {
                        pq.push(p2);
                    }
                    pq.push(p1);
                }
                else
                {
                    ans.push_back(p1.second);
                    p1.first--;
                    
                    if(p1.first > 0)
                    {
                        pq.push(p1);
                    }
                }
                
            }		    
        }
        return ans;
    }
};