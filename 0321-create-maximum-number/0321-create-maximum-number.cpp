class Solution {
    vector<int> maxLex(const vector<int> &v,const int &k)
    {
        int n=v.size();
        vector<int> max;
        for(int i=0; i<n;i++)
        {
            while( max.size() && max.back()<v[i] && (n-(i+1)>=k-max.size()))
                max.pop_back();
            if(max.size()<k)
                max.push_back(v[i]);
        }
        return max;
    }

    bool isLexGreater(const vector<int> &lex1, const vector<int> &lex2, int a, int b, const int &m, const int &n)
    {
        while(a<m || b<n)
        {
            if(a>=m) return false;
            else if(b>=n) return true;
            else if(lex1[a]>lex2[b]) return true;
            else if(lex1[a]<lex2[b]) return false;
            else a++,b++;
        }
        return true;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int> ans;
        for(int i=0,j=k;i<=k;i++,j--)
        {
            vector<int> lex1 = maxLex(nums1,i);
            vector<int> lex2 = maxLex(nums2,j);
            vector<int> merged;
            int a=0,b=0,m=lex1.size(),n=lex2.size();
            while(a<m||b<n)
            {
                if(a>=m) merged.push_back(lex2[b++]);
                else if(b>=n) merged.push_back(lex1[a++]);
                else if(lex1[a]>lex2[b]) merged.push_back(lex1[a++]);
                else if(lex1[a]<lex2[b]) merged.push_back(lex2[b++]);
                else if(isLexGreater(lex1,lex2,a,b,m,n)) merged.push_back(lex1[a++]);
                else merged.push_back(lex2[b++]);
            }
            if(merged.size()==k && ans<merged)
                ans=merged;
        }
        return ans;
        /*
        int m = nums1.size(), n = nums2.size();
        vector<int> vec(k, 0), main(m+n);
        unordered_map<int, int> mp;

        int j = 0;
        for(int i = 0; i < m+n; i++)
        {
            if(i < m)
                main[i] = nums1[i];
            else
                main[i] = nums2[j++];
        }
        j = 0;

        while(k > 0)
        {
            int maxi = INT_MIN, x = -1;
            for(int i = 0; i < m+n; i++)
            {
                maxi = max(maxi, main[i]);
                if(main[i] == maxi)
                    x = i;
            }
            
            if(mp[maxi] == 0)
            {
                vec[j++] = maxi;
                k--;
                mp[maxi]++;
                
            }
            main[x] = -1;
        }
        return vec; */
    }
};