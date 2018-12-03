/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution //iterator
{
public:
  string reverseWords(string s)
  {
  	string::iterator it = s.begin();
  	string temp ="";
  	string res = "";
  	while (it != s.end())
  	{
  		if (*it != ' ')
  		{
  			temp += *it;
  		}
  		else
  		{
  			for (int i = temp.size() - 1; i > -1; i--)
  			{
  				res += temp[i];
  			}
  			res += " ";
  			temp = "";
  		}
  		it++;
  	}
  	for (int i = temp.size() - 1; i > -1; i--)
  	{
  		res += temp[i];
  	}
    return res;
    //runtime: 16ms
  }
};

class Solution //find
{
public:
  string reverseWords(string s)
  {
    int st = 0;
  	int ed = 0;
  	string res = "";
  	string find_word(" ");
  	string::size_type pos = s.find(find_word);
  	while (pos != std::string::npos)
  	{
  		ed = pos;
  		for (int i = ed - 1; i >= st; i--)
  		{
  			res += s[i];
  		}
  		res += " ";
  		st = ed + 1;
  		pos = s.find(find_word, pos + 1);
  	}
  	for (int i = s.length() - 1; i >= st; i--)
  	{
  		res += s[i];
  	}
    return res;
    //runtime: 24ms
  }
};
