class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left =0, right = heights.size()-1;
        int area = 0, maxArea =0;
        while(left < right)
        {
            int w = right -left;
            int h = min(heights[left], heights[right]);
            area = w*h;
            maxArea = max(maxArea, area);

            if(heights[left] < heights[right])
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
        return maxArea;
    }
};
