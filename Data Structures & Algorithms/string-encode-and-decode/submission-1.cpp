class Solution {
public:

    string encode(vector<string>& strs) {
       string result;
       for(string s : strs)
       {
        result+=to_string(s.size());
         result+='#';
         result+=s;
       }
       return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
         
         int i=0;

         while(i<s.size())
         {
            int len =0;

            int j =i;
            while(s[j] != '#')
            {
                len = len*10 + (s[j]-'0');
                j++;
            }

            i=j+1; // skip #

            string word="";
            for(int k=0;k<len;k++)
            {
               word += s[i+k];
            }
            result.push_back(word);
            i+=len;
         }
    return result;
    }
};
