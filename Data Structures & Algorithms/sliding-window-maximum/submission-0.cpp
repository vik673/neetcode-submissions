class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j =0;
        list<int> lst;
        vector<int> result;
        while(j<nums.size())
        {
            while(!lst.empty() && lst.back() < nums[j])
            {
                lst.pop_back();
            }
                
            lst.push_back(nums[j]);

            if(j-i+1 == k)
            {
               result.push_back(lst.front());

                if(lst.front() ==nums[i]){
                    lst.pop_front();
                }

                i++;
            }

            j++;
        }
        return result;
    }
};
