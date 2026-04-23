class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorAll=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            xorAll ^= nums[i];
        }

        for(int i=0;i<n+1;i++)
        {
            xorAll^=i;
        }
        return xorAll;
    }
};
