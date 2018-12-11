/*
Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate
Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.
It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.

Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].
*/

class Solution //direct
{
public:
  string shortestCompletingWord(string licensePlate,
    vector<string>& words)
  {
    vector<string> ori = words;
    vector<int> words_size(words.size(), 0);
  	int temp = 10000, index = 0;
  	for (auto i: licensePlate)
  	{
  		if (i >= 'A' && i <= 'Z')
  	    i += (char)(32);
  		if (i >= 'a' && i <= 'z' )
  		{
  			for (int j = 0; j < words.size(); j++)
  			{
  				string::iterator it = find(words[j].begin(),
          words[j].end(), i);
  				if (it != words[j].end())
  				{
  					words[j].erase(it, it + 1);
  					words_size[j] = words[j].size();
  				}
  				else
  				{
  					words[j] = "0";
  					words_size[j] = 11000;
  				}
  			}
  		}
  	}
  	for (int t = 1, temp = words_size[0];
      t < words_size.size(); t++)
  	{
  		if (temp > words_size[t])
  		{
  			temp = words_size[t];
  			index = t;
  		}
  	}
    return ori[index];
    //runtime: 8ms
  }
};

class Solution //erase and sort
{
public:
  string shortestCompletingWord(string licensePlate,
    vector<string>& words)
  {
    vector<string> ori = words;
  	for (auto i: licensePlate)
  	{
  		if (i >= 'A' && i <= 'Z')
  		  i += (char)(32);
  		if (i >= 'a' && i <= 'z' )
  		{
  			for (int j = 0; j < words.size(); j++)
  			{
  				string::iterator it = find(words[j].begin(),
          words[j].end(), i);
  				if (it != words[j].end())
  				    words[j].erase(it, it + 1);
  				else
  				    words[j] = "0";
  			}
  		}
  	}
  	int temp = 1000, index = 0;
  	for (int j = 0; j < words.size(); j++)
  	{
  		if (words[j] != "0")
  		{
  			if (temp > words[j].size())
  			{
  				temp = words[j].size();
  				index = j;
  			}
  		}
  	}
    return ori[index];
    //runtime: 24ms?
  }
};
