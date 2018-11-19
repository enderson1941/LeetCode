/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.

Example 1:
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:
2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int>& A)
    {
      vector<int> index_odd;
    	vector<int> index_even;
    	for (int i = 0; i < A.size(); i++)
    	{
    		if (i % 2 == 0)//even
    		{
    			if (A[i] % 2 != 0)
    			{
    				index_even.push_back(i);
    			}
    		}
    		else//odd
    		{
    			if (A[i] % 2 != 1)
    			{
    				index_odd.push_back(i);
    			}
    		}
    	}
    	for (int j = 0; j < index_even.size(); j++)
    	{
    		swap(A[index_even[j]], A[index_odd[j]]);
    	}
      return A;
      //runtime: 96ms
    }
};
