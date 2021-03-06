/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.


Example 1:
Input: "ab-cd"
Output: "dc-ba"
Example 2:
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

Note:
S.length <= 100
33 <= S[i].ASCIIcode <= 122
S doesn't contain \ or "
*/

class Solution
{
public:
  string reverseOnlyLetters(string S)
  {
    char temp;
  	int start = -1;
  	int end = S.size();
  	while (start != end)
  	{
  		start++;
  		end--;
  		while (S[start]<'A' || S[start]>'Z' && S[start] <'a'
      || S[start]>'z')
  		{
  			start++;
  			if (start > end)
  			{
  				break;
  			}
  		}
  		while (S[end]<'A' || S[end]>'Z' && S[end] <'a'
      || S[end]>'z')
  		{
  			end--;
  			if (start > end)
  			{
  				break;
  			}
  		}
  		if (start > end)
  		{
  			break;
  		}
  		temp = S[start];
  		S[start] = S[end];
  		S[end] = temp;
  	}
    return S;
  }
};
