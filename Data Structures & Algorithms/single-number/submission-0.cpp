class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorAll =0;
        for(int i=0;i<nums.size();i++)
        {
           xorAll ^= nums[i];
        }
        return xorAll;
    }
};
