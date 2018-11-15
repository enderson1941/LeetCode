/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:
Input: "Hello"
Output: "hello"
Example 2:
Input: "here"
Output: "here"
Example 3:
Input: "LOVELY"
Output: "lovely"

*/

class Solution
{
public:
  string toLowerCase(string str)
  {
    //A-Z: 65-91
    //a-z: 97-123
    int index;
    string res = "";
    for (int i = 0; i < str.size(); i++)
    {
      index = (int)str[i];
      if (index > 64 && index < 92)
      {
        str[i] = (char)(97 + index - 65);
      }
      res += str[i];
    }
    return res;
    // runtime: 0ms
  }
};
