class Solution {
public:
    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& le,
               vector<int>& ud,
               vector<int>& ld,
               int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (le[row] == 0 &&
                ld[row + col] == 0 &&
                ud[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';
                le[row] = 1;
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, le, ud, ld, n);

                board[row][col] = '.';
                le[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> le(n, 0), ud(2 * n - 1, 0), ld(2 * n - 1, 0);

        solve(0, board, ans, le, ud, ld, n);
        return ans;
    } 
};