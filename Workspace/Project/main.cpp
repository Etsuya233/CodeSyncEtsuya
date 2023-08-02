#include <iostream>
using namespace std;
int main(){
	int target;
	cin >> target;
	if(target == 1){
		cout << 1;
		return 0;
	}
	int arr[100000] = { 0, 1, 1};
	int layerCnt, layer = 3, cnt = 2, ans = 3;
	while(true){
		layerCnt = (layer + 1) / 2;
		arr[cnt + 1] = 1;
		if(layer % 2){
			for(int i = cnt + 2; i <= cnt + layerCnt - 1; i++){
				arr[i] = arr[i - layerCnt] + arr[i - layerCnt + 1];
				if(arr[i] == target){
					cout << ans + i - cnt;
					return 0;
				}
			}
			arr[cnt + layerCnt] = arr[cnt] * 2;
			if(arr[cnt + layerCnt] == target){
				cout << ans + layerCnt;
				return 0;
			}
		} else {
			for(int i = cnt + 2; i <= cnt + layerCnt; i++){
				arr[i] = arr[i - layerCnt - 1] + arr[i - layerCnt];
				if(arr[i] == target){
					cout << ans + i - cnt;
					return 0;
				}
			}
		}
		cnt += layerCnt;
		ans += layer;
		layer++;
	}
}