/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:
If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]

Example 1:
Input: "IDID"
Output: [0,4,1,3,2]
Example 2:
Input: "III"
Output: [0,1,2,3]
Example 3:
Input: "DDI"
Output: [3,2,0,1]

Note:
1 <= S.length <= 10000
S only contains characters "I" or "D".
*/

class Solution
{
public:
  vector<int> diStringMatch(string S)
  {
    int inc = 0;
  	int dec = S.size();
  	int sum = 0;
  	vector<int> series;
  	string::iterator it = S.begin();
  	for (int j = 1; j < dec + 1; j++)
  	{
  		sum += j;
  	}
  	while (it != S.end())
  	{
  		if (*it == 'I')//increase
  		{
  			series.push_back(inc);
  			sum -= inc;
  			inc++;
  		}
  		else//decrease
  		{
  			series.push_back(dec);
  			sum -= dec;
  			dec--;
  		}
  		it++;
  	}
  	series.push_back(sum);
    return series;
    //runtime: 36ms
  }
};
