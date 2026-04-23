class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> prefixProd;
       vector<int> suffixProd;
        int n= nums.size();
       prefixProd.push_back(1);

       int mul = 1;
       for(int i=1;i<nums.size();i++)
       {
           mul = nums[i-1]*mul;
           prefixProd.push_back(mul);
       }

       suffixProd.push_back(1);
       mul =1;
       for(int i= n-2;i>=0;i--)
       {
          mul = nums[i+1]*mul;
          suffixProd.push_back(mul);
       }

       reverse(suffixProd.begin(), suffixProd.end());
       
       for(int i=0;i<n;i++)
       {
        nums[i]=prefixProd[i]*suffixProd[i];
       }
       return nums;
    }
};
