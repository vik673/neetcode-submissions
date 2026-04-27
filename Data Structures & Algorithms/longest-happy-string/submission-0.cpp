class Solution {
public:
    string longestDiverseString(int a, int b, int c) {


        priority_queue<pair<int, char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});


        string res="";
        while(!pq.empty())
        {
           auto p = pq.top();
           pq.pop();

           int n = res.size();
           if(n >=2 && res[n-1] == p.second && res[n-2] == p.second)
           {
            if(pq.empty()) break;

            auto q = pq.top();
            pq.pop();
            res+= q.second;
            q.first--;

            if(q.first > 0) pq.push(q);
            pq.push(p);  
           }
           else
           {
             res+= p.second;
             p.first--;
             if(p.first >0) pq.push(p);
           }
        }
        return res;
    }
};