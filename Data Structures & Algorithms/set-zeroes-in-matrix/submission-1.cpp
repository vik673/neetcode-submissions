class Solution {
    void setRowZero(vector<vector<int>>& matrix, int rowIndex)
    {
      int col = matrix[0].size();

      for(int i=0;i<col;i++)
      {
        if(matrix[rowIndex][i] == -1) continue;
        matrix[rowIndex][i] =0;
      }
    }

    void setColZero(vector<vector<int>>& matrix, int colIndex)
    {
      int row = matrix.size();

      for(int i=0;i<row;i++)
      {
        if(matrix[i][colIndex] == -1) continue;
         matrix[i][colIndex] =0;
      }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                  matrix[i][j] = -1;
                }
            }
        }
       
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == -1)
                {
                    setRowZero(matrix, i);
                    setColZero(matrix, j);
                }
            }
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] =0;
                }
            }
        }
        
    }
};
