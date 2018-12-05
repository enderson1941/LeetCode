/*
You're now a baseball game point recorder.
Given a list of strings, each string can be one of the 4 following types:
Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.

Each round's operation is permanent and could have an impact on the round before and the round after.
You need to return the sum of the points you could get in all the rounds.
Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation:
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.

Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.

Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.
*/

class Solution //stack
{
public:
  int calPoints(vector<string>& ops)
  {
    vector<string>::iterator it = ops.begin();
  	vector<int> score;
  	int cnt = 0;
  	int sum = 0;
  	while (it != ops.end())
  	{
  		if (*it == "C")
  		{
  			sum -= score[cnt - 1];
  			score.pop_back();
  			cnt -= 2;
  		}
  		else if (*it == "D")
  		{
  			score.push_back(2 * score[cnt - 1]);
  			sum += 2 * score[cnt - 1];
  		}
  		else if (*it == "+")
  		{
  			score.push_back(score[cnt - 1]+ score[cnt - 2]);
  			sum += score[cnt - 1] + score[cnt - 2];
  		}
  		else
  		{
  			score.push_back(stoi(*it));
  			sum += stoi(*it);
  		}
  		cnt++;
  		it++;
  	}
    return sum;
    //runtime: 4ms
  }
};

class Solution //map
{
public:
  int calPoints(vector<string>& ops)
  {
    vector<string>::iterator it = ops.begin();
  	map<int, int> key;
  	map<int, int>::iterator index;
  	int cnt = 0;
  	int sum = 0;
  	int temp = 0;
  	while (it != ops.end())
  	{
  		if (*it == "C")
  		{
  			ops.erase(it - 1, it + 1);
  			cnt--;
  			it = ops.begin() + cnt;
  		}
  		else
  		{
  			cnt++;
  			it++;
  		}
  	}

  	for (int i = 0; i < ops.size(); i++)
  	{
  		if (ops[i] == "D")
  		{
  			index = key.find(i - 1);
  			temp = 2 * (index->second);
  			sum += temp;
  		}
  		else if (ops[i] == "+")
  		{
  			temp = key.find(i - 1)->second +
        key.find(i - 2)->second;
  			sum += temp;
  		}
  		else
  		{
  			temp = stoi(ops[i]);
  			sum += stoi(ops[i]);
  		}
  		key.insert(pair<int, int>(i, temp));
  	}
    return sum;
    //runtime: 8ms
  }
};
