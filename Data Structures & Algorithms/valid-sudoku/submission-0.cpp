class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            vector<bool> seen(10, false);
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.') continue;
                int num = board[i][j] -'0';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        for(int i=0;i<9;i++)
        {
            vector<bool> seen(10, false);
            for(int j=0;j<9;j++)
            {
               if(board[j][i] == '.') continue;
                int num = board[j][i] -'0';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }

       
    // Check 3x3 boxes
    for(int boxRow = 0; boxRow < 3; boxRow++) {
        for(int boxCol = 0; boxCol < 3; boxCol++) {
            vector<bool> seen(10, false);
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    char val = board[boxRow*3 + i][boxCol*3 + j];
                    if(val == '.') continue;
                    int num = val - '0';
                    if(seen[num]) return false;
                    seen[num] = true;
                }
            }
        }
    }

    return true;

    }
};
