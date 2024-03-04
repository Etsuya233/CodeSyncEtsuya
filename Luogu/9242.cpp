#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ListNode{
	int h, t; //第i个数字的开头与结尾 
} node;

int n;
int arr[100005] = {0};
node li[100005];
int pre[100005][10] = {0};
int dp[100005][10] = {0, 1};
int ans = 0;

int main(){
	cin >> n; //数字个数 
	for(int i = 1; i <= n; i++){
		cin >> arr[i]; //输入每一个数字 
		int temp = arr[i]; //下面是预处理 
		int t = temp % 10, h;
		while(temp > 0){
			h = temp % 10;
			temp /= 10;
		}
		li[i].h = h;
		li[i].t = t;
		pre[i][t] = i;
		for(int j = 0; j <= 9; j++){
			if(j != t) pre[i][j] = pre[i - 1][j];
		}
	}
	//接龙数列指前一个数字的结尾与该数字相同，该数字的结尾与下一个数字的开头相同
	//如 12 23 35，这三个数字就能组成接龙数列。
	//现在要求最长接龙子数列的长度，即12 23 44 35 这个数列，最长接龙子数列的长度为3（12 23 35） 
	// pre[i - 1][li[i].h] 指前i-1个数字中，结尾与第i个数字的开头相等的下标 
	for(int i = 2; i <= n; i++){
		dp[i] = dp[pre[i - 1][li[i].h]] + 1;
		ans = max(dp[i], ans);
	}
	cout << n - ans << "\n";
} 

