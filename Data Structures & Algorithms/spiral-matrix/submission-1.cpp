class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int top =0, left = 0, bottom = row-1, right = col-1;
        vector<int> result;
        if(row == 1)
        {
            for(int i=0;i<col;i++)
            {
               result.push_back(matrix[top][i]);
            }
        } 
        else if(col == 1)
        {
            for(int i=0;i<row;i++)
            {
                result.push_back(matrix[i][left]);
            }
        }
        else
        {
            while(left<=right && top <= bottom)
            {
            for(int i=left;i<=right;i++)
            {
               result.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i = top; i<=bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right)
            {
                for(int i = bottom; i>=top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
            left++;
            }
            }
        }
        return result;
    }
};
