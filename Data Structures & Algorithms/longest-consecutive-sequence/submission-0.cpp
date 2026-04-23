class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n : nums)
        {
            st.insert(n);
        }
        
        int count =0, maxCount =0;
        int len =0, curr =0;
        for(int n : st)
        {
          if(!st.count(n-1))
          {
            curr = n;
            len = 1;
            while(st.count(curr+1))
            {
                curr++;
                len++;
            }

            maxCount = max(maxCount, len);
          }
        }
        return maxCount;
    }
};
