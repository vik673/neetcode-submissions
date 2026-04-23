class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       bool isAlternate = true;
       int n = word1.size(), m = word2.size();
       int i=0, j=0;
       string res;
       while(i<n && j<m)
       {
        if(isAlternate)
        {
            res +=word1[i++];
            isAlternate = false;
        }
        else
        {
            res +=word2[j++];
            isAlternate = true;
        }
       } 

       while(i<n)
       {
        res +=word1[i++];
       }

       while(j<m)
       {
        res +=word2[j++];
       }

       return res;
    }
};