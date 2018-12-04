/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.



Example:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
*/

class Solution

public:
  vector<string> findWords(vector<string>& words)
  {
    string f = "qwertyuiop";
  	string s = "asdfghjkl";
  	string t = "zxcvbnm";
  	vector<string> res;
    char key;
  	for (int i = 0; i < words.size(); i++)
  	{
  		bool res_[3] = { true,true,true };
  		for (int j = 0; j < words[i].size(); j++)
  		{
  			if ((int)words[i][j] > 63 && (int)words[i][j] < 93)
  			{
  				key = (char)((int)words[i][j] + 32);
  			}
  			else
  			{
  				key = words[i][j];
  			}
  			if (f.find(key) == -1)
  			{
  				res_[0] = false;
  			}
  			if (s.find(key) == -1)
  			{
  				res_[1] = false;
  			}
  			if (t.find(key) == -1)
  			{
  				res_[2] = false;
  			}
  		}
  		if (res_[0] + res_[1] + res_[2])
  		{
  			res.push_back(words[i]);
  		}
  	}
    return res;
    //runtime: 0ms
  }
};
