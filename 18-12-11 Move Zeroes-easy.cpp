/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution //erase then push_back
{
public:
  void moveZeroes(vector<int>& nums)
  {
    int temp = 0;
    vector<int>::iterator it = find(nums.begin(),
    nums.end(), 0);
  	while (it !=nums.end())
  	{
  		nums.erase(it, it + 1);
  		temp++;
  		it = find(nums.begin(), nums.end(), 0);
  	}
  	for (int i = 0; i < temp; i++)
  	{
  		nums.push_back(0);
  	}
  }
  //runtime: 16ms
};

class Solution //direct
{
public:
  void moveZeroes(vector<int>& nums)
  {
    int num = 0;
    vector<int>::iterator it = find(nums.begin(),
    nums.end(), 0);
  	for (int j = 0, k = nums.size(); j < k; j++)
  	{
  		if (it == nums.begin() + k - num)
  		{
  			break;
  		}
  		else
  		{
  			num++;
  			nums.erase(it, it + 1);
  			nums.push_back(0);
  			it = find(nums.begin(),
        nums.begin() + k - num, 0);
  		}
  	}
  }
  //runtime: 28ms?
};
