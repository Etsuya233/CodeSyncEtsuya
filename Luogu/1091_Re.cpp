#include <bits/stdc++.h>
using namespace std;

int rise[110] = {0};
int down[110] = {0};
int n;
int arr[110] = {0};

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	//rise
	for(int i = 2; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			if(arr[j] <= arr[i]){
				rise[i] = rise[j] + 1;
				break;
			}
		}
	}
	//down
	for(int i = n - 1; i >= 1; i--){
		for(int j = i + 1; j <= n; j++){
			if(arr[j] >= arr[i]){
				down[i] = down[j] + 1;
				break;
			}
		}
	}
	//travel
	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, rise[i] + down[i] + 1);
	}
	cout << n - res;
	return 0;
	
	
}
