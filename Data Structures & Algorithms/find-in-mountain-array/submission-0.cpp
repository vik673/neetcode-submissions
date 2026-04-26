/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int binarySearchAsc(MountainArray &mountainArr, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int val = mountainArr.get(mid);
            if(val == target)
            {
               return mid;
            }
            else if(val < target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return -1;
    }

     int binarySearchDsc(MountainArray &mountainArr, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int val = mountainArr.get(mid);
            if(val == target)
            {
               return mid;
            }
            else if(val < target)
            {
                right = mid-1;
            }
            else
            {
                 left = mid+1;
            }
        }
        return -1;
    }

    int findpeak(MountainArray &mountainArr)
    {
       int left =0, right =mountainArr.length()-1;
       while(left <= right)
       {
        int mid = left + (right - left)/2;
        if(mountainArr.get(mid) <= mountainArr.get(mid+1))
        { 
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
       }
       return left;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findpeak(mountainArr);

        int index = binarySearchAsc(mountainArr, 0, peak, target);
        if(index != -1) return index;

        return binarySearchDsc(mountainArr, peak+1, mountainArr.length()-1, target);
    }

};