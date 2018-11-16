/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.
Example 1:
Input: "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.

Example 2:
Input: "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
*/

//solution 1
class Solution
{
public:
  bool judgeCircle(string moves)
  {
    bool res = true;
    int move[] = { 0,0 };
    string::iterator it=moves.begin();
    while (it != moves.end())
    {
      if (*it == 'L')
      {
        move[0]++;
      }
      if (*it == 'R')
      {
        move[0]--;
      }
      if (*it == 'U')
      {
        move[1]++;
      }
      if (*it == 'D')
      {
        move[1]--;
      }
      it++;
    }
    if (move[0] || move[1])
    {
      res = false;
    }
    return res;
    //runtime: 12ms
  }
};

//solution 2
class Solution
{
public:
  bool judgeCircle(string moves)
  {
    bool res = false;
    int move[] = { 0,0 };
    for (int i = 0; i < moves.size(); i++)
    {
      if(moves[i] == 'L')
        move[0]++;
      if(moves[i] == 'R')
        move[0]--;
      if(moves[i] == 'U')
        move[1]++;
      if(moves[i] == 'D')
        move[1]--;
    }
    if (move[0] == 0 && move[1] == 0)
    {
      res = true;
    }
    return res;
    //runtime: 16ms
  }
};

//solution 3
class Solution
{
public:
  bool judgeCircle(string moves)
  {
    bool res = false;
    int move[] = { 0,0 };
    map<string, int>dir_;
    map<string, int>::iterator it;
    dir_.insert(pair<string, int>("L", 1));
    dir_.insert(pair<string, int>("R", -1));
    dir_.insert(pair<string, int>("U", 1));
    dir_.insert(pair<string, int>("D", -1));
    for (int i = 0; i < moves.size(); i++)
    {
    	it = dir_.find(moves.substr(i, 1));
    	if (it->first == "L" || it->first == "R")
    	{
    		move[0] += it->second;
    	}
    	if (it->first == "U" || it->first == "D")
    	{
    		move[1] += it->second;
    	}
    }
    if (move[0] == 0 && move[1] == 0)
    {
    	res = true;
    }
    return res;
    //runtime: 40ms
  }
};
