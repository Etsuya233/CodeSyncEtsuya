#include<bits/stdc++.h>
using namespace std;
int n,m,i,dp[10];
string a;//���ַ����洢���������� 
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=n;i--;){
//    	cout << i << "\n";
    	cin>>a;
    	dp[a[a.size()-1]-48]=max(dp[a[a.size()-1]-48],dp[a[0]-48]+1);//���a�й��� 
	}
	for(i=0;i<=9;i++){
		m=max(m,dp[i]);//ȡ���ֵ 
		if(m == dp[i]){
			cout << i;
		}	
	}
	cout<<n-m; 
}
