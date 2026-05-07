class Solution {
public:

    int calculate(vector<vector<int>>& grid,int i, int j, int row, int col, vector<vector<int>>& dp){

        //base case
        if(i>=row || j>=col ) return 1e9;
        if(i==row-1 && j==col-1 ) return grid[i][j];

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = grid[i][j] + calculate(grid, i, j+1, row, col, dp);
        int down = grid[i][j] + calculate(grid, i+1, j, row, col, dp);

        return dp[i][j] = min(right,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col, -1));
        int i =0, j = 0;
        return calculate(grid,i, j, row, col, dp);
    }
};