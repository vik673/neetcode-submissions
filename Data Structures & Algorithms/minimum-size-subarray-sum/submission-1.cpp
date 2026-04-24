class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0, j=0;
        int sum =0, result =INT_MAX;

        while(j<nums.size())
        {
          sum += nums[j];
           
          while(sum >= target)
          {
            result = min(result, j-i+1);
            sum -= nums[i];
            i++;
          }

          j++;
        }

         return result == INT_MAX ? 0 : result;
    }
};