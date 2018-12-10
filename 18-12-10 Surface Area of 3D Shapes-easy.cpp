/*
On a N * N grid, we place some 1 * 1 * 1 cubes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
Return the total surface area of the resulting shapes.


Example 1:
Input: [[2]]
Output: 10
Example 2:
Input: [[1,2],[3,4]]
Output: 34
Example 3:
Input: [[1,0],[0,2]]
Output: 16
Example 4:
Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:
Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
*/

class Solution
{
public:
  int surfaceArea(vector<vector<int>>& grid)
  {
    int n = grid.size();
    int res = 0;
    int num = 0;
    for(auto i = 0; i < n; i++)
    {
      for(auto j = 0; j < n; j++)
      {
        if(grid[i][j])
        {
         res += grid[i][j];
         num += grid[i][j]- 1;
        }
        if(j)
          num += min(grid[i][j], grid[i][j-1]);
        if(i)
          num += min(grid[i][j], grid[i-1][j]);
      }
    }
    return (res * 6 - num * 2);
    //runtime: 8ms?
  }
};
