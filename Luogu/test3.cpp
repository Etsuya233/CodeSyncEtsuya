#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C(int below, int up);

typedef struct Matrix{
	int arr[2][2];
} ma;

ma me = {
	1, 1,
	1, 0
};

int parent[5] = {-1};

int prime[2000] = {0};

void primeFind(int maxn);

int main(){
//	cout << C(5, 3);
	
//	for(int i = 0; i < 4; i++){
//		cout << *(*me.arr + i) << " ";
//	}

	primeFind(1000);
	for(int i = 1; i <= prime[0]; i++){
		cout << prime[i] << " ";
	}

}

ll C(int below, int up){
	ll ret = 1;
	for(int i = below, j = 1; j <= up; i--, j++){
		ret = ret * i / j;
	}
	return ret;
}

void primeFind(int maxn){
	int vis[maxn + 1] = {0};
	for(int i = 2; i <= maxn; i++){
		if(!vis[i]){
			prime[0]++;
			prime[prime[0]] = i;
		}
		for(int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//?
		}
	}
}























void primeFind2(int maxn){
	int vis[maxn + 1] = 0;
	for(int i = 2; i <= maxn; i++){
		if(!vis[i]){
			prime[++prime[0]] = i;
		}
		for(int j = 1; j <= prime[prime[0]]; j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

void discreet(int target, int size){
	int book[size];
	sort(target, target + size);
	for(int i = 0; i < size; i++){
		book[i] = target[i];
	}
	int reu = unique(book, book + n) - book;
	for(int i = 0; i < size; i++){
		target[i] = lower_bound(book, book + reu, target[i]);
	}
}

//st±í
void stlization(int arr, int n){
	int dp[n + 1][22];
	//init
	for(int i = 1; i <= n; i++) dp[i][0] = arr[i];
	//dp
	for(int j = 1; j <= 22; j++){
		for(int i = 1; i + (1 << j) - 1 <= n; i++){
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void query(int l, int r){
	int k = log(r - l + 1);
	return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}








