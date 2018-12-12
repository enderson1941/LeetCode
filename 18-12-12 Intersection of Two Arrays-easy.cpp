/*
Given two arrays, write a function to compute their intersection.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
*/

class Solution
{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    vector<int> answer;
  	sort(nums1.begin(), nums1.end());
  	sort(nums2.begin(), nums2.end());
  	vector<int>::iterator end1 = unique(nums1.begin(), nums1.end());
  	vector<int>::iterator end2 = unique(nums2.begin(), nums2.end());
  	vector<int>::iterator it = nums1.begin();
  	while (it != end1)
  	{
  		vector<int>::iterator index = find(nums2.begin(), end2, *it);
  		if (index != end2)
  		{
  			answer.push_back(*it);
  		}
  		it++;
  	}
  	return answer;
    //runtime: 8ms?
  }
};
