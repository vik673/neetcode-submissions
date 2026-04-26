class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timebasedmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timebasedmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &v =  timebasedmap[key];
        int left =0, right = v.size()-1;
        string ans;
        while(left <=right)
        {
            int mid = left + (right-left)/2;
            if(v[mid].first <= timestamp)
            {
                ans = v[mid].second;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return ans;
    }
};
