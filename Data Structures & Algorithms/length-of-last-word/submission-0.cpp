class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count =0, last_word_count =0;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]== ' ')
          {
              if(count > 0) last_word_count = count;
              count =0; 
          }
          else
          {
            count++;
          }
          
        }
        if(count > 0) last_word_count = count;
        return last_word_count;
    }
};