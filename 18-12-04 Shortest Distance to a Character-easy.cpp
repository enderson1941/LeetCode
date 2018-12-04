/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.
Example 1:
Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

Note:
S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/

class Solution
{
public:
  vector<int> shortestToChar(string S, char C)
  {
    vector<int> res;
  	vector<int> pos_;
  	int pos = S.find(C);
  	while (pos != -1)
  	{
  		pos_.push_back(pos);
  		pos = S.find(C, pos + 1);
  	}
  	for (int i = 0; i < S.size(); i++)
  	{
  		int dis = 100000;
  		for (int j = 0; j < pos_.size(); j++)
  		{
  			if (dis > abs(i - pos_[j]))
  			{
  				dis = abs(i - pos_[j]);
  			}
  		}
  		res.push_back(dis);
  	}
    return res;
    //runtime: 8ms
  }
};
