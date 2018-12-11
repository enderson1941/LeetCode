/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
Example:
Input: 38
Output: 2
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

/*
explaination: Digit root problem
https://en.wikipedia.org/wiki/Digital_root

input:   0 1 2 3 4 5 6 7 8 9 10 11 12 13 ... 19 20 21 ...
output:  0 1 2 3 4 5 6 7 8 9  1  2  3  4 ...  1  2  3 ...


*/

class Solution
{
public:
    int addDigits(int num)
    {
      return 1 + (num - 1) % 9;
      //runtime: 4ms
    }
};
