class Solution {
    int getNext(int n)
    {
        int rem = 0;
        int sum =0;
        while(n>0)
        {
            rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
       unordered_set<int> seen;
       while(n != 1 && seen.find(n) == seen.end())
       {
          seen.insert(n);
          n = getNext(n);
       }
       
        return n==1;
    }
};
