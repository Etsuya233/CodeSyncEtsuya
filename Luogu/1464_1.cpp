#include<iostream>
#include<algorithm>
// #include<vector>
// #include<cmath>
#define debug(a) cout<<#a<<"="<<a<<endl;
using namespace std;
#define ll long long
// const int  MAX_INT = 0x7fffffff;
int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	// cin>>t;
	// ++t;
	// while(--t)
	// {
	
	// }
	ll dp[21][21][21];
	for(int i=0;i<=20;++i)
		for(int j=0;j<=20;++j)
			for(int k=0;k<=20;++k)
	{
		if(i==0||j==0||k==0)
			dp[i][j][k]=1;
		else if(i<j&&j<k)
			dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
		else
			dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][k][j-1]-dp[i-1][j-1][k-1];
	}
	ll a,b,c;
	ll t;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
			break;
		else if(a<=0||b<=0||c<=0)
			t=1;
		else if(a>20||b>20||c>20)
			t=dp[20][20][20];
		else
			t=dp[a][b][c];
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<t<<endl;
	}
	return 0;
}
