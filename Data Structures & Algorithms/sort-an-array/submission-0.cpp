class Solution {
    
    int partition(vector<int> &arr, int left, int right)
    {
        int i = left;
        int pivot = left;
        for(int j = i+1;j<=right;j++)
        {
            if(arr[j]< arr[pivot])
            {
                i=i+1;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[i], arr[pivot]);

        return i;
    }

    void quickSort(vector<int> &arr, int left, int right)
    {
      if(left>=right) return;
      int q = partition(arr, left, right);
      quickSort(arr, left, q-1);
      quickSort(arr, q+1, right);
    }
    public:

    vector<int> sortArray(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        quickSort(nums, left, right);
        return nums;
    }
};