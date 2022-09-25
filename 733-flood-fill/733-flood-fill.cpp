//class Solution {
//public:
    
    
    class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int Color, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = Color; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != Color) {
                dfs(nrow, ncol, ans, image, Color, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int Color) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, Color, delRow, delCol, iniColor); 
        return ans; 
    }
};
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
   // }
//};