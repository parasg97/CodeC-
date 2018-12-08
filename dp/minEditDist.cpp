#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int minVal(int a,int b,int c){
	return min(a,min(b,c));
}

int giveAns(string s1,string s2){
	//s1 row, s2 col
	int row=1+s1.size();
	int col=1+s2.size();
	int res[row][col];

	for (int i = 0; i <=row; ++i)
	{
		for (int j = 0; j <=col; ++j)
		{
			if(i==0){
				res[i][j]=j;
			}else if(j==0){
				res[i][j]=i;
			}else{
				if(s1[i-1]==s2[j-1]){
					res[i][j]=res[i-1][j-1];
				}else{
					res[i][j]=giveAns(res[i-1][j-1]+1,res[i][j-1]+1,res[i-1][j]+1);
				}
			}
		}
	}
	return res[row][col];
}

int main(int argc, char const *argv[])
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<giveAns(s1,s2);
	return 0;
}