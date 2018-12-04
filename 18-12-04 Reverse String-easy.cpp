/*
Write a function that takes a string as input and returns the string reversed.
Example 1:
Input: "hello"
Output: "olleh"
Example 2:
Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
*/

class Solution //swap
{
public:
  string reverseString(string s)
  {
    for (int i = 0; i < s.length()/2; i++)
  	{
  		swap(s[i], s[s.length() - 1 - i]);
  	}
    return s;
    //runtime: 4ms
  }
};

class Solution //iterator
{
public:
  string reverseString(string s)
  {
    string res;
    string::iterator it = s.begin();
  	while (it != s.end())
  	{
  		res.insert(res.begin(), 1, *it);
  		it++;
  	}
    return res;
    //runtime: ?184ms
  }
};
