#include <iostream>
using namespace std;

int n;
int arr[210];
int temp[210];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		for(int j = 1; j <= m; j++){
			cin >> arr[j];
			temp[j] = arr[j];
		}
		int cnt = 1;
		while(true){
			int k;
			for(k = 1; k <= m; k++){
				if(k != temp[k]) break;
			}
			if(k > m){
				cout << cnt << "\n";
				break;
			}
			cnt++;
			for(int k = 1; k <= m; k++){
				temp[k] = arr[temp[k]];
			}
		}
	}
	return 0;
}
