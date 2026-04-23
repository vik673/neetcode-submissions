class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int count =0, maxlen=0;

        int i=0, j=0;
        while(j<s.size())
        {
            if(!st.count(s[j]))
            {
                st.insert(s[j]);
                maxlen = max(maxlen, j-i+1);
            }
            else
            {
                while(st.count(s[j]))
                {
                    st.erase(s[i]);
                    i++;
                }
                 st.insert(s[j]);
                maxlen = max(maxlen, count);
            }
            j++;
        }
        return maxlen;
    }
};
