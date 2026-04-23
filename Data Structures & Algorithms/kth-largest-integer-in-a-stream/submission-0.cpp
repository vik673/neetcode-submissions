class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth =k;
        for(auto &n : nums)
        {
            pq.push(n);
            if(pq.size()>kth)
               pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
         if(pq.size()>kth)
               pq.pop();
        return pq.top();
    }
};
