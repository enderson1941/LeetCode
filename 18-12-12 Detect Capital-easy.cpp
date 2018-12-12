/*
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False
*/

class Solution
{
public:
  bool detectCapitalUse(string word)
  {
    int num =0;
    int index=-1;
    for(auto i = 0; i< word.size(); i++)
    {
      if(word[i] >= 'A' && word[i]<= 'Z' )
      {
        num++;
        index = i;
      }
    }
    if( num == word.size() || index < 1 )
        return true;
    return false;
    //runtime: 8ms?
  }
};
