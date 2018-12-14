/*
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.
Formally, a parentheses string is valid if and only if:
It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
*/

class Solution
{
public:
  int minAddToMakeValid(string S)
  {
    string::iterator it = find(S.begin(), S.end(), '(');
  	while (it != S.end())
  	{
  		if (it + 1 != S.end() && *(it+1) == ')')
  		{
  			S.erase(it, it + 2);
  			it = find(S.begin(), S.end(), '(');
  		}
  		else
  		  it = find(it + 1, S.end(), '(');
  	}
    return S.size();
    //runtime: 4ms?
  }
};
