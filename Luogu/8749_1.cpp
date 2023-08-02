#include <iostream>
using namespace std;

int arr[100010] = {0};
int target;

int main(){
	cin >> target;
	if(target == 1){
		cout << 1;
		return 0;
	}
	arr[1] = 1;
	int cnt = 1;
	for(int layer = 2; true; layer++){
		for(int j = layer; j >= 1; j--){
			arr[j] = arr[j] + arr[j - 1];
			cnt++;
			if(arr[j] == target){
				cout << cnt;
				return 0;
			}
		}
	}
}
