#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> arr[1005];
bool cmpNumber(int a, int b);
int ans = 0;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		arr[a % k].push_back(a);
	}
	for(int i = 0; i < k; i++) sort(arr[i].begin(), arr[i].end(), cmpNumber);
	for(int i = 0; i < k; i++){
		if(arr[i].size() == 0) continue;
		for(int j = i; j < k; j++){
			if(arr[j].size() == 0) continue;
			for(int f = 0; f <= 1; f++){
				if(f){
					//k
					int target = k - i - j;
					if(target == k) target = 0;
					if(target < j) continue;//RE
					if(arr[target].size() == 0) continue;
					if(i == j && j == target){
						if(arr[i].size() >= 3) ans = max(ans, arr[i][0] + arr[i][1] + arr[i][2]);
					} else if(i == j){
						if(arr[i].size() >= 2) ans = max(ans, arr[i][0] + arr[i][1] + arr[target][0]);
					} else if(i == target){
						if(arr[i].size() >= 2) ans = max(ans, arr[i][0] + arr[i][1] + arr[j][0]);
					} else if(j == target){
						if(arr[j].size() >= 2) ans = max(ans, arr[j][0] + arr[j][1] + arr[i][0]);
					} else {
						ans = max(ans, arr[i][0] + arr[j][0] + arr[target][0]);
					}
				} else {
					//2k
					int target = 2 * k - i - j;
					if(target >= k) target -= k;
					if(target < 0) break;//RE
					if(arr[target].size() == 0) break;
					if(i == j && j == target){
						if(arr[i].size() >= 3) ans = max(ans, arr[i][0] + arr[i][1] + arr[i][2]);
					} else if(i == j){
						if(arr[i].size() >= 2) ans = max(ans, arr[i][0] + arr[i][1] + arr[target][0]);
					} else if(i == target){
						if(arr[i].size() >= 2) ans = max(ans, arr[i][0] + arr[i][1] + arr[j][0]);
					} else if(j == target){
						if(arr[j].size() >= 2) ans = max(ans, arr[j][0] + arr[j][1] + arr[i][0]);
					} else {
						ans = max(ans, arr[i][0] + arr[j][0] + arr[target][0]);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

bool cmpNumber(int a, int b){
	return a > b;
}
