class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /*sort(nums.begin(), nums.end());
        int j=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[j-1]) 
             {return true;}
            j++;
        }
        return false;*/

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) return true;
        }
        return false;
    }
};