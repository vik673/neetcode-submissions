class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int &n : nums)
        {
           freq[n]++;
        }

        for(int i=1;i<=n+1;i++)
        {
            if(freq.find(i) == freq.end())
            {
                return i;
            }
        }
        return 0;
    }
};