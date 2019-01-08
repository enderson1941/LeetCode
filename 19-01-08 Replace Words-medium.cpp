/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
You need to output the sentence after the replacement.
Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/

class Solution//directly replace
{
public:
  string replaceWords(vector<string>& dict, string sentence)
  {
    size_t index;
  	for (auto i : dict)
  	{
  		index = sentence.find(i);
  		while (index != -1)
  		{
  			if (index == 0 || sentence[index - 1] == ' ')
  			{
          int mark = sentence.find_first_of(" ", index, 1) == -1 ? sentence.size()
    					: sentence.find_first_of(" ", index, 1);
  				sentence.erase(sentence.begin() + index + i.size(),
          sentence.begin() + mark);
  			}
  			index = sentence.find(i, index + 1);
  		}
  	}
    return sentence;
  }
};

class Solution//break and replace then rebuild
{
public:
  string replaceWords(vector<string>& dict, string sentence)
  {
    string answer;
    vector<string> words;
    string temp = "";
    sentence += " ";
    for (auto i : sentence)
    {
      if (i != ' ')
      {
        temp += i;
      }
      else
      {
        words.push_back(temp);
        temp = "";
      }
    }
    for (auto j : dict)
    {
      for (int k = 0; k < words.size(); k++)
      {
        if (words[k].find(j) == 0)
        {
          words[k] = j;
        }
      }
    }
    for (auto p : words)
    {
      answer += p + " ";
    }
    answer.erase(answer.begin() + answer.size() - 1);
    return answer;
  }
};
