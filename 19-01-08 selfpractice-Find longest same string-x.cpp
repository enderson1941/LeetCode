/*
Find longest same characterstics in two strings.
such as

string s1 = "mmgyuthg";
string s2 = "fhhteqgyuthsmmnbgy";

longest part would be "gyuth", and the answer is 5.
*/
string s1 = "mmgyuthg";
string s2 = "fhhteqgyuthsmmnbgy";
int answer = 0;

int k1 = s1.size();//row
int k2 = s2.size();//col

//form an 2-dimension Matrix
int** n2Arr = new int*[k1];
for (int i = 0; i < k1; i++)
	n2Arr[i] = new int[k2]{0};
//initialize a Matrix
//	int arr2[][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };

//set same element as 1
for (int j = 0; j < k1; j++)
{
	for (int k = 0; k < k2; k++)
	{
		if (s2[k] == s1[j])
		{
			n2Arr[j][k] = 1;
		}
	}
}

//check number of 1 in the diagonal line
for (int m = 0; m < k1; m++)
{
	int row = m;
	int col = 0;
	int temp = 0;
	while (row < k1 && col < k2)
	{
		cout << n2Arr[row][col] << " ";
		if (n2Arr[row][col] == 1)
		{
			temp++;
			if (temp > answer)
			{
				answer = temp;
			}
		}
		row++;
		col++;
	}
	cout << endl;
}

for (int n = 1; n < k2; n++)
{
	int row = 0;
	int col = n;
	int temp = 0;
	while (row < k1 && col < k2)
	{
		cout << n2Arr[row][col] << " ";
		if (n2Arr[row][col] == 1)
		{
			temp++;
			if (temp > answer)
			{
				answer = temp;
			}
		}
		row++;
		col++;
	}
	cout << endl;
}
cout << answer << endl;
