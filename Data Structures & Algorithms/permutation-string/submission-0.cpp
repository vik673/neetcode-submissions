class Solution {
    bool compare(vector<int>& f1, vector<int>& f2)
    {
        int n = f1.size();
        for(int i=0;i<n;i++)
        {
            if(f1[i] != f2[i])
              return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int i=0, j=0, freq1Count=0;
        vector<int> freq1(26,0), freq2(26,0);
        bool result = false;
        for(char ch : s1)
        {
            freq1[ch -'a']++;
            freq1Count++;
        }

        while(j<s2.size())
        {
            freq2[s2[j]-'a']++;
            
            while((j-i+1) > freq1Count)
            {
                freq2[s2[i]-'a']--;
                i++;
            }

            if((j-i+1) == freq1Count)
            {
                if(compare(freq1, freq2)) return true;
            }

            j++;
        }
        return result;
    }

};
