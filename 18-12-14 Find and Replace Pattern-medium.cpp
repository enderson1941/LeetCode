/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
Return a list of the words in words that match the given pattern.
You may return the answer in any order.

Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
*/

class Solution 
{
public:
  vector<string> findAndReplacePattern(vector<string>& words,
    string pattern)
  {
    vector<string> list;
  	words.insert(words.begin(), pattern);
  	bool op_sgn = true;
  	vector<string>::iterator wds = words.begin();
  	while (wds != words.end())
  	{
  		int index = 0;
  		string temp = "";
  		map<int, int>input;
  		for (int i = 0; i < (*wds).size(); i++)
  		{
  			map<int, int>::iterator it =
        input.find(int('n' - (*wds)[i]));
  			if (it == input.end())
  			{
  				temp += to_string(index);
  				input.insert(pair<int, int>(int('n' - (*wds)[i]), index));
  			}
  			else
  			{
  				temp += to_string(it->second);
  			}
  			index++;
  		}
  		if (op_sgn)
  		{
  			pattern = temp;
  			op_sgn = false;
  		}
  		else
        if (temp == pattern)
          list.push_back(*wds);
  		wds++;
  	}
    return list;
    //runtime: 4ms?
  }
};
