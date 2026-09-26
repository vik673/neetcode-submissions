class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapS, mapT;

        if(s.size() != t.size()) return false;
        int i=0;
        for(int i=0;i<s.size();i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            if(mapS.count(c2))
            {
                if(mapS[c2] != c1) return false;
            }
            else
            {
                mapS[c2] = c1;
            }

            if(mapT.count(c1))
            {
                if(mapT[c1] != c2) return false;
            }
            else
            {
                mapT[c1] = c2;
            }
        }
        return true;
    }
};