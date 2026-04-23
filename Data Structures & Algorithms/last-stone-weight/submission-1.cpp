class Solution {
    priority_queue<int> maxh;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
        {
            maxh.push(stones[i]);
        }

        while(maxh.size()>1)
        {
            int top = maxh.top();
            maxh.pop();
            int secTop = maxh.top();
            maxh.pop();
            int result = abs(secTop - top);
            maxh.push(result);
        }
        return maxh.top();
    }
};
