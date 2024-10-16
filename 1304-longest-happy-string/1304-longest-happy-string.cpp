class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int,char>> pq;
        string ans = "";

        if(a>0)
            pq.push({a,'a'});

        if(b>0)
            pq.push({b,'b'});

        if(c>0)
            pq.push({c,'c'});

        while(!pq.empty())
        {
            int f1 = pq.top().first;
            int ch = pq.top().second;
            pq.pop();

            if(ans.size() > 0 && ans.back() != ch)
            {
                int tmp = min(2,f1);
                for(int j = 0; j < tmp; j++)
                {
                    ans += ch;
                }
                f1 -= tmp;
            }
            else if(ans.size() == 0)
            {
                int tmp = min(2,f1);
                for(int j=0;j<tmp;j++)
                {
                    ans += ch;
                }
                f1 -= tmp;
            }
            else
            {
                if(pq.size() == 0)
                    break;

                int f2 = pq.top().first;
                char c = pq.top().second;
                pq.pop();

                ans += c;
                f2--;

                if(f2 > 0)
                    pq.push({f2,c});
            }
            
            if(f1>0)
                pq.push({f1,ch});
        }
        return ans;
    }
};