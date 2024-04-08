#include<bits/stdc++.h>
using namespace std;
int n,m,i,dp[10];
string a;//用字符串存储，便于运算 
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=n;i--;){
//    	cout << i << "\n";
    	cin>>a;
    	dp[a[a.size()-1]-48]=max(dp[a[a.size()-1]-48],dp[a[0]-48]+1);//如果a有贡献 
	}
	for(i=0;i<=9;i++){
		m=max(m,dp[i]);//取最大值 
		if(m == dp[i]){
			cout << i;
		}	
	}
	cout<<n-m; 
}
