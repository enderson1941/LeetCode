/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.
We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
The rules of Goat Latin are as follows:
If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

Example 1:
Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:
Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/

class Solution //direct
{
public:
  string toGoatLatin(string S)
  {
    string vowel = "a e i o u A E I O U";
  	string res= "", temp = "", as ="";
    S += " ";
  	while (S.size())
  	{
      if (S[0] == ' ')
  		{
        as += "a";
        if (find(vowel.begin(), vowel.end(), temp[0]) == vowel.end())
  			{
  				temp.insert(temp.end(), temp[0]);
  				temp.erase(temp.begin(), temp.begin() + 1);
  			}
  			res += temp + "ma" + as + " ";
  			temp = "";
  		}
  		else
        temp += S.front();
  		S.erase(S.begin(), S.begin() + 1);
  	}
    res.erase(res.end() - 1, res.end());
    return res;
    //runtime: 0ms
  }
};

class Solution //iterator
{
public:
  string toGoatLatin(string S)
  {
    string vowel = "a e i o u A E I O U";
  	string res;
  	string::iterator it = S.begin();
  	int index = 0;
  	while (it != S.end())
  	{
  		string temp = "";
  		while (*it != ' ')
  		{
  			temp += *it;
  			it++;
  			if (it == S.end())
  				break;
  		}
  		index++;
  		if (find(vowel.begin(), vowel.end(), temp[0]) == vowel.end())
  		{
  			temp.insert(temp.end(), temp[0]);
  			temp.erase(temp.begin(), temp.begin() + 1);
  		}
  		temp += "ma";
  		for (int i = 0; i < index; i++)
  		  temp += "a";
  		res += temp + " ";
  		if (it != S.end())
  			it++;
  	}
  	res.erase(res.end() - 1, res.end());
    return res;
    //runtime: 0ms
  }
};
