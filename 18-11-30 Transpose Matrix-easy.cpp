/*
Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:
Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Note:
1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>>& A)
  {
    vector<vector<int>> res;
    if(A.size() < 1)
        return res;
    for(int n = 0; n < A[0].size(); n++)
    {
      vector<int> temp;
      for(int m = 0; m < A.size(); m++)
      {
          temp.push_back(A[m][n]);
      }
      res.push_back(temp);
    }
   return res;
   //runtime: 20ms
  }
};
