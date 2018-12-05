/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Example 1:
Input: [2,2,1]
Output: 1
Example 2:
Input: [4,1,2,1,2]
Output: 4
*/

class Solution //XOR
{
public:
  int singleNumber(vector<int>& nums)
  {
    int res = 0;
    for(int i=0; i<nums.size();i++)
    {
      res ^=nums[i];
    }
    return res;
    //runtime: 8ms?
  }
};

/*
Approach 4: Bit Manipulation Concept

If we take XOR of zero and some bit, it will return that bit

a⊕0=a

If we take XOR of two same bits, it will return 0
a⊕a=0a

a⊕b⊕a=(a⊕a)⊕b=0⊕b=b

So we can XOR all bits together to find the unique number.
*/
