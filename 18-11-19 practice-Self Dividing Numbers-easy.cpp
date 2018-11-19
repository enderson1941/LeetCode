/*
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Note:
The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

class Solution
{
public:
  vector<int> selfDividingNumbers(int left, int right)
  {
    vector<int> digits_;
    for (int t = left; t <= right; t++)
    {
      bool op_sgn = true;
      int temp;
      temp = t;
      while (temp > 0)
      {
        int digt = temp % 10;
        if (digt != 0)
        {
          if (t % digt != 0)
          {
            op_sgn = false;
            break;
          }
        }
        else
        {
          op_sgn = false;
        }
        temp /= 10;
      }
      if (op_sgn)
      {
        digits_.push_back(t);
      }
    }
    return  digits_;
    //runtime: 0ms
  }
};
