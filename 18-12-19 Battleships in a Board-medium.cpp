/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
*/

class Solution
{
public:
  int countBattleships(vector<vector<char>>& board)
  {
    int ans = 0;
  	for (int i = 0; i < board.size(); i++)
  	{
  		for (int j = 0; j < board[0].size(); j++)
  		{
  			if (board[i][j] == 'X')
  			{
  				if ((j > 0 && board[i][j-1] == 'X') ||
          (i > 0 && board[i-1][j] == 'X'))
  				{
  				  continue;
  				}
          ans++;
  			}
  		}
  	}
    return ans;
    //runtime: 4ms
  }
};
