/*
Given an integer, write a function to determine if it is a power of two.
Example 1:
Input: 1
Output: true
Explanation: 20 = 1
Example 2:
Input: 16
Output: true
Explanation: 24 = 16
Example 3:
Input: 218
Output: false
*/

class Solution
{
public:
  bool isPowerOfTwo(int n)
  {
    if(n <= 0)
        return false;
    if(n == 1)
        return true;
    bool answer = true;
  	bool sign = true;
  	while (sign && n > 1)
  	{
  		if (n%2 != 0)
  		{
  			sign = false;
  			answer = false;
  		}
  		else
  		{
  			n /= 2;
  		}
  	}
    return answer;
    //runtime: 4ms
  }
};
