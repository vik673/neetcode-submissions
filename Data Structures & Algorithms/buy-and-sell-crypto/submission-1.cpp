class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int minVal=prices[0], maxDiff = prices[1]-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            minVal=min(minVal, prices[i]);
            maxDiff = max(maxDiff, prices[i] - minVal);
        }
        return maxDiff;
    }
};
