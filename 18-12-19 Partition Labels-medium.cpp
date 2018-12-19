/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

class Solution
{
public:
  vector<int> partitionLabels(string S)
  {
    vector<int> answer;
  	vector<int> temp(1, 0);
  	int num_min = S.size();
  	int num_max = 0;
  	for (int i = 0; i < S.size(); i++)
  	{
  		int inter1 = S.find(S[i]);
  		int inter2 = S.find_last_of(S[i]);
  		if (inter1 > num_max)
  		{
  			temp.push_back(inter1);
  			num_min = inter1;
  		}
  		else if (inter1 < num_min)
  		{
  			num_min = inter1;
  		}
  		if (inter2 > num_max)
  		{
  			num_max = inter2;
  		}
  	}
  	temp.push_back(S.size());
  	for (int j = 1; j < temp.size(); j++)
  	{
  		answer.push_back(temp[j] - temp[j - 1]);
  	}
    return answer;
    //runtime: 8ms?
  }
};
