#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int arr[100050];
int Max[100050][22] = {0};

int query(int a, int b);
void calc();

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	calc();
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a, b));
	}
	return 0;
}

void calc(){
	//��ʼ����ΪMax[i][0]��ֵ��i+2^0��������
	//��ʵ���������Max[i][0]��ֱ�Ӵ�ֵ��
	for(int i = 1; i <= n; i++){
		Max[i][0] = arr[i];
	}
	//����Max����
	for(int j = 1; j <= 21; j++){
		for(int i = 1; i + (1 << j) - 1 <= n; i++){
			Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){
	int k = log2(r - l + 1);
	return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}
