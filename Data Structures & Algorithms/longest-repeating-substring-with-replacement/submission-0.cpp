class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int i=0, j= 0;
        int ans =0 , maxFreq=0;
        while(j<s.size())
        {
            freq[s[j]]++;
            
            maxFreq = max(maxFreq,  freq[s[j]]);

            while((j-i+1) - maxFreq > k)
            {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);

            j++;
        }
        return ans;
    }
};
