class Solution {
    int maximum(vector<int>& piles)
    {
        int maxElement=-1;
        for(int i=0;i<piles.size();i++)
        {
            maxElement = max(maxElement, piles[i]);
        }
        return maxElement;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r= maximum(piles);
        int ans=0, hour =0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            hour = 0;

            for(int pile : piles)
            {
                hour += ceil((double)pile/mid);
            }

            if(hour<=h)
            {
                ans = mid;
                r= mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }
};
