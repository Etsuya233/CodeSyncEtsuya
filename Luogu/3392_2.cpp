#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<queue>
#include<map>
#include<vector> 
#include<cstdio>
#include<cmath>
#include <iomanip>
using namespace std;
typedef pair<int,char> PII;
const int N=55;
int w[N],b[N],r[N];  
int n,m;
int sum;
string s;
int check(char c)
{
	int num=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]!=c)
		{
			num++;
		}
	}
	return num;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		w[i]=w[i-1]+check('W');//这三行分别表示前i行的该字母的个数 
		b[i]=b[i-1]+check('B');
		r[i]=r[i-1]+check('R');
	}
	int ans=2e9;
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans=min(ans,w[i]+b[j]-b[i]+r[n]-r[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

