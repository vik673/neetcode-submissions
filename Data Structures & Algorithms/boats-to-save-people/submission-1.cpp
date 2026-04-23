class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(), people.end());

       int left =0, right = people.size()-1;
       int sum = 0, count=0;
       while(left <= right)
       {
         sum = people[left] + people[right];
         if(sum <= limit)
         { 
            left++;
         }
         right--;
         count++;
       }
       return count; 
    }
};