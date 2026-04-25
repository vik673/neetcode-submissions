class Solution {
public:
    string minWindow(string s, string t) {
     unordered_map<char, int> mp;
     for(auto &ch: t)
     {
        mp[ch]++;
     }  

     int i=0, j=0;
     int count = mp.size();
     int minlen = INT_MAX;
     int start =0;
    
     while(j<s.size())
     {
        if(mp.find(s[j])!= mp.end())
        {
            mp[s[j]]--;
            if(mp[s[j]] == 0)
             count--;
        }
     
      
      while(count ==0)
      {
        if(minlen > j-i+1)
        {
            start =i;
            minlen = j-i+1;
        }

        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]++;
            if(mp[s[i]]==1)
              count++;
        }
        i++;
      }
       j++;
     }
     if(minlen == INT_MAX) return "";
     return s.substr(start, minlen);
    }
};
