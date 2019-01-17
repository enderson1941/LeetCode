/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.

Note: The length of given array won't exceed 10000.
*/

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int>& nums)
  {
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++)
  	{
  		bool sign = false;
  		vector<int> check(nums.begin() + i, nums.end());
  		check.insert(check.end(), nums.begin(), nums.begin() + i);
  		for (int j = 0; j < check.size(); j++)
  		{
  			if (nums[i] < check[j])
  			{
  				answer.push_back(check[j]);
  				sign = true;
  				break;
  			}
  		}
      if (!sign)
      {
        answer.push_back(-1);
      }
    }
    return answer;
  }
};
