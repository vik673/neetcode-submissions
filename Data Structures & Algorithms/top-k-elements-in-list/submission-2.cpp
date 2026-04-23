class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int &n : nums)
        {
            freq[n]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> minh;

        for(auto &p : freq)
        {
            int key = p.first;
            int value = p.second;

            minh.push({value, key});

            if(minh.size() > k)
                minh.pop();
        } 

        vector<int> result;
        while(!minh.empty())
        {
           result.push_back(minh.top().second);
               minh.pop();
        }
        return result;
    }
};
