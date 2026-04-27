class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char, int> freq;
       priority_queue<pair<int, char>> pq;

       for(auto& ch : s)
       {
          freq[ch]++;
       }

       for(auto &m : freq)
       {
          pq.push({m.second, m.first});
       }

       string res ="";
       pair<int , char> prev ={0,'#'};
       while(!pq.empty())
       {
        auto curr = pq.top();
            pq.pop();

            res += curr.second;
            curr.first--;

            // push previous back if still available
            if (prev.first > 0) {
                pq.push(prev);
            }

            // update prev
            prev = curr;
       }

       if(res.size() != s.size()) return "";
       return res;
    }
};