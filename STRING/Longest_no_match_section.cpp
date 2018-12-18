#include <iostream>
using namespace std;

int longest_match(string s1,string s2)
{
	int n = s1.size();
	int m = s2.size();
	int lm[n+1][m+1];
	int ans = -1;
	ans = 0;
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=m;j++)
		{
			if(i == 0 || j == 0)
			{
				lm[i][j] = 0;
			}
			else if(s1[i-1] != s2[j-1])
			{
				lm[i][j] = 0;
			}
			else
			{
				lm[i][j] = 1 + lm[i-1][j-1];
				ans = max(ans,lm[i][j]);
			}
		}
	}
	return ans;
}
int main() {
	// your code goes here
	string s1 = "abcd";
	string s2 = "bcd";
	//cin >> s1 >> s2;
	cout << longest_match(s1,s2) << endl;

}
