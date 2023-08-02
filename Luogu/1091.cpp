#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, res = 0;
int arr[105];
int lis[105];

int LISL(int a);
int LISR(int a);

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		int l = LISL(i), r = LISR(i);
		res = max(res, l + r + 1);
	}
	cout << n - res;
}

int LISL(int a){
	memset(lis, 0, sizeof(lis));
	lis[0] = arr[a];
	int len = 1;
	for(int i = a - 1; i >= 0; i--){
		int* loc = lower_bound(lis, lis + len, arr[i], greater<int>());
		*loc = arr[i];
		if(lis[len] > 0) len++;
	}
	return len - 1;
}

int LISR(int a){
	memset(lis, 0, sizeof(lis));
	lis[0] = arr[a];
	int len = 1;
	for(int i = a + 1; i < n; i++){
		int* loc = lower_bound(lis, lis + len, arr[i], greater<int>());
		*loc = arr[i];
		if(lis[len] > 0) len++;
	}
	return len - 1;
}