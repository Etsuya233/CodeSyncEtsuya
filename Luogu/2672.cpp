#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Family{
	int dest, val;
} fa;

int n, pre[100005], post[100005], sum[100005];
fa arr[100005];

bool cmpFamily(fa a, fa b){return a.val > b.val; }

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].dest;
	}
	for(int i = 1; i <= n; i++){
		cin >> arr[i].val;
	}
	sort(arr + 1, arr + 1 + n, cmpFamily);
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + arr[i].val;
		pre[i] = max(pre[i - 1], 2 * arr[i].dest);
	}
	for(int j = n; j >= 1; j--){
		post[j] = max(post[j + 1], 2 * arr[j].dest + arr[j].val);
	}
	for(int i = 1; i <= n; i++){
		cout << max(sum[i] + pre[i], sum[i - 1] + post[i]) << "\n";
	}
}
