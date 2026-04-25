class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(auto ch : tasks)
        {
            freq[ch]++;
        } 

        priority_queue<pair<int, int>> maxh;
        for(auto item : freq)
        {
            maxh.push({item.second, 0});
        }

        queue<pair<int, int>> q;
        int time =0;
        while(!q.empty() || !maxh.empty())
        {
            time++;
            // check if there is a tsk in pq and process it.
            if(!maxh.empty())
            {
                auto task = maxh.top();
                maxh.pop();
                task.first--; // reduce the frquency
                if(task.first >0)
                {
                    // update the execution time.
                    task.second = time + n;
                    q.push(task);
                }
            }
            // shift the active process to the pq
            if(!q.empty() && q.front().second == time)
            {
                maxh.push(q.front());
                q.pop();
            }
            
        }
        return time;

    }
};
