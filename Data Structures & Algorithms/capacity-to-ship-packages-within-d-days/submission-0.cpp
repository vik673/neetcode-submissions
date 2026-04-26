class Solution {
    bool canShip(vector<int> &weights, int mid, int days)
    {
        int currLoad =0;
        int requiredDays =1;
       
        for(int i=0;i<weights.size();i++)
        {
            if(currLoad + weights[i] > mid)
            {
                 requiredDays++;
                 currLoad =0;
            }
           currLoad+= weights[i];
        }
        return requiredDays <=days;
    }
    int sum(vector<int> &weights)
    {
        int sum =0;
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
        }
        return sum;
    }
     public:

    int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = sum(weights);
    int ans=0;
    while(left <= right)
    {
         int mid = (left+right)/2;
        if(canShip(weights, mid, days))
        {
            ans = mid;
            right = mid -1;
        }
        else
        {
            left = mid+1;
        }
    }
    return ans;
    }
};