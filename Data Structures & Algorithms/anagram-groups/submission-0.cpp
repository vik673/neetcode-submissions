class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> map;
       vector<vector<string>> res;

       for(string s : strs)
       {
          string sSorted = s;
          sort(sSorted.begin(), sSorted.end());
          map[sSorted].push_back(s);
       } 

       for(auto &s : map)
       {
         res.push_back(std::move(s.second));
       }
       return res;
    }
};
