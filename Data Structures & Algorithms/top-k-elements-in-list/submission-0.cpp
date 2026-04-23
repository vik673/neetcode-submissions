class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minH;
        vector<int> result;
        unordered_map<int, int> freq;


        for(int i : nums)
        {
            freq[i]++;
        }

        for(auto &it : freq)
        {
            minH.push({it.second, it.first});
            if(minH.size() > k)
             minH.pop();
        }


        while(!minH.empty())
        {
            result.push_back(minH.top().second);
            minH.pop();
        }
        return result;
    }
};
