/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:
Input: J = "z", S = "ZZ"
Output: 0
Note:
S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

class Solution
{
public:
  int numJewelsInStones(string J, string S)
  {
    int count = 0;
    int size_J = J.size();
    int size_S = S.size();
    for (int j = 0; j < size_J; j++)
    {
        for (int s = 0; s < size_S; s++)
        {
            if (J[j] == S[s])
            {
                count++;
            }
        }
    }
    return count;
    //runtime: 4ms
  }
};
///acquaintance
int a[] = { 1,2,3,4,5 };
string str = "abcde";
char* chr = "abcde";
//数组类型
int sz_ = sizeof(a) / sizeof(a[0]);
cout << sz_ << endl;
//字符串类型
sz_ = str.length();
cout << "length " << sz_ << endl;
sz_ = str.size();
cout << "size " << sz_ << endl;
cout << sz_ << endl;
//字符指针-要先赋值给string
sz_ = sizeof(chr);
cout << "size chr " << sz_ << endl;
sz_ = sizeof(chr[0]);
cout << "size chr[0] " << sz_ << endl;
str = chr;
sz_ = str.size();
cout << "size " << sz_ << endl;
