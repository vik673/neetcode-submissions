class Solution {
public:
    int appendCharacters(string s, string t) {
        
      int j=0;
      int m = t.size();
      for(int i=0;i<s.size() && j < m; i++)
      {
         if(s[i]==t[j]) j++;
      }
      return m-j;
    }
};