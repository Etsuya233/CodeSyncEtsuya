#include <iostream>
#include <cstring>
using namespace std;

int arr[22] = {0};

int main(){
	int a;
	cin >> a;
	for(int i = 0; i < a; i++){
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;
		for(int j = 0; j < 2 * n; j++){
			int b, c;
			cin >> b >> c;
			arr[b] ++;
			arr[c] ++;
		}
		bool res = true;
		for(int j = 1; j <= n; j++){
			if(arr[j] != 4){
				res = false;
				break;
			}
		}
		if(res) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
