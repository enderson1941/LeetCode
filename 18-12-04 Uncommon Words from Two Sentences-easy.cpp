/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Return a list of all uncommon words.
You may return the list in any order.


Example 1:
Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:
Input: A = "apple apple", B = "banana"
Output: ["banana"]

Note:
0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

class Solution //stack
{
public:
  vector<string> uncommonFromSentences(string A, string B)
  {
    string add = A + " " + B;
  	string temp = "";
  	vector<string> stack;
  	vector<string> res;
  	string::iterator it = add.begin();
  	vector<string>::iterator it1;
  	while (it != add.end())
  	{
  		if (*it != ' ')
  		{
  			temp += *it;
  		}
  		else
  		{
  			stack.push_back(temp);
  			temp = "";
  		}
  		it++;
  	}
  	stack.push_back(temp);
  	it1 = stack.begin();
  	while (it1 != stack.end())
  	{
  		int num = 0;
  		for (int i = 0; i < stack.size(); i++)
  		{
  			if (*it1 == stack[i])
  			{
  				num++;
  			}
  		}
  		if (num == 1)
  		{
  			res.push_back(*it1);
  		}
  		it1++;
  	}
    return res;
    //runtime: 0ms
  }
};

class Solution //map
{
public:
  vector<string> uncommonFromSentences(string A, string B)
  {
    string add = A + " " + B;
  	string temp = "";
  	vector<string> stack;
  	vector<string> res;
  	string::iterator it = add.begin();
  	map<string, int>key;
  	while (it != add.end())
  	{
  		if (*it != ' ')
  		{
  			temp += *it;
  		}
  		else
  		{
  			auto pos = key.find(temp);
  			if (pos == key.end())
  			{
  				key.insert(pair<string, int>(temp, 0));
  			}
  			else
  			{
  				key[temp] = 1;//key.insert_or_assign(temp, 1);
  			}
  			temp = "";
  		}
  		it++;
  	}
  	auto pos = key.find(temp);
  	if (pos == key.end())
  	{
  		key.insert(pair<string, int>(temp, 0));
  	}
  	else
  	{
  		key[temp] = 1;//key.insert_or_assign(temp, 1);
  	}
  	map<string, int>::iterator it1 = key.begin();
  	while (it1 != key.end())
  	{
  		if (it1->second == 0)
  		{
  			res.push_back(it1->first);
  		}
  		it1++;
  	}
    return res;
    //runtime: 4ms
  }
};
