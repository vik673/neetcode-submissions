class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
         vector<int> greatest_element;
         int n = arr.size();
         int max = arr[n-1];
         greatest_element.push_back(-1);

         for(int i= n-2;i>=0;i--)
         {
            greatest_element.push_back(max);
            if(arr[i] > max)
               max = arr[i];
         } 
         reverse(greatest_element.begin(), greatest_element.end());
         return greatest_element;
    }
};