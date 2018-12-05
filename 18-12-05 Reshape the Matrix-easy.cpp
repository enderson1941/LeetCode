/*
If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.

Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/

class Solution //stack
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums,
    int r, int c)
  {
    int index = 0;
  	int row = nums.size();
  	int col = nums[0].size();
  	vector<int> temp_;
  	vector<vector<int>> answer(r, vector<int>(c));
  	if (r*c != row*col)
  	{
  		return nums;
  	}
  	for (int i = 0; i < row; i++)
  	{
  		for (int j = 0; j < col; j++)
  		{
  			if (index != c)
  			{
  				temp_.push_back(nums[i][j]);
  				index++;
  			}
  			else
  			{
  				answer.push_back(temp_);
  				temp_.clear();
  				index = 0;
  				temp_.push_back(nums[i][j]);
  				index++;
  			}
  		}
  	}
  	answer.push_back(temp_);
    return answer;
    //runtime: 32ms
  }
};

class Solution //direct
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums,
    int r, int c)
  {
  	int row = 0;
  	int col = 0;
  	vector<vector<int>> answer(r, vector<int>(c));
  	if (r*c != nums.size()*nums[0].size())
  	{
  		return nums;
  	}
  	for (int i = 0; i < nums.size(); i++)
  	{
  		for (int j = 0; j < nums[0].size(); j++)
  		{
  			if (col == c)
  			{
  				row++;
  				col = 0;
  			}
  			answer[row][col] = nums[i][j];
  			col++;
  		}
  	}
    return answer;
    //runtime: 24ms
  }
};
