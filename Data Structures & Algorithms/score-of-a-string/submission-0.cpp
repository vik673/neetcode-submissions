class Solution {
public:
    int scoreOfString(string s) {
      int total_score  =0;
      for(int i=1;i<s.size();i++)
      {
        total_score += abs(s[i] - s[i-1]);
      }  
      return total_score;
    }
};