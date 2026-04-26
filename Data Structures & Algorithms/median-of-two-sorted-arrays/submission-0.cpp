class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int begin1 = 0, end1= n1;
        while(begin1<=end1)
        {
            int i1= (begin1+end1)/2;
            int i2 = (n1+n2+1)/2 -i1;
            int min1 = (i1==0) ? INT_MIN : nums1[i1-1];
            int max1 = (i1==n1) ? INT_MAX : nums1[i1];
            int min2 = (i2==0) ? INT_MIN : nums2[i2-1];
            int max2 = (i2==n2) ? INT_MAX : nums2[i2];

            if(min1 <= max2 && min2 <= max1)
            {
                  if((n1+n2)%2 ==0) 
                     return (max(min1, min2) + min(max1, max2)) / 2.0;
                  else
                    return ((double)max(min1,min2));
            }
            else if(min1 > max2)
            {
                end1= i1-1;
            }
            else
            {
              begin1 = i1+1;
            }
        }
        return -1;
    }
};
