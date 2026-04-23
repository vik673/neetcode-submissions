class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[j-1]) 
             {return true;}
            j++;
        }
        return false;
    }
};