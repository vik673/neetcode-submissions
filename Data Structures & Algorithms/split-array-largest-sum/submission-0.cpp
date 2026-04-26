class Solution {
    bool isValid(vector<int>& nums, int mid, int splitK)
    {
        int currCount = 0;
        int currentSplit = 1;
        for(int i=0;i<nums.size();i++)
        {
           if(currCount + nums[i]> mid)
           {
             currentSplit++;
             currCount=0;
           }
           currCount += nums[i];
        }
        return currentSplit <= splitK;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        
        int mx =0;
        int sum =0, ans=0;
        for(int i=0;i<nums.size();i++)
        {
           mx = max(mx, nums[i]);
           sum += nums[i];
        }

        int left = mx, right = sum;

        while(left <= right)
        {
           int mid = (left + right)/2;
           if(isValid(nums, mid, k))
           {
             ans = mid;
             right = mid-1;
           }
           else
           {
             left = mid+1;
            
           }
        }
        return ans;
    }
};