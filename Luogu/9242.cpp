#include <iostream>
#include <algorithm>
using namespace std;

typedef struct ListNode{
	int h, t; //��i�����ֵĿ�ͷ���β 
} node;

int n;
int arr[100005] = {0};
node li[100005];
int pre[100005][10] = {0};
int dp[100005][10] = {0, 1};
int ans = 0;

int main(){
	cin >> n; //���ָ��� 
	for(int i = 1; i <= n; i++){
		cin >> arr[i]; //����ÿһ������ 
		int temp = arr[i]; //������Ԥ���� 
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
	//��������ָǰһ�����ֵĽ�β���������ͬ�������ֵĽ�β����һ�����ֵĿ�ͷ��ͬ
	//�� 12 23 35�����������־�����ɽ������С�
	//����Ҫ������������еĳ��ȣ���12 23 44 35 ������У�����������еĳ���Ϊ3��12 23 35�� 
	// pre[i - 1][li[i].h] ָǰi-1�������У���β���i�����ֵĿ�ͷ��ȵ��±� 
	for(int i = 2; i <= n; i++){
		dp[i] = dp[pre[i - 1][li[i].h]] + 1;
		ans = max(dp[i], ans);
	}
	cout << n - ans << "\n";
} 

