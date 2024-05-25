#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll arr[2004][2004] = {0};
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		arr[x1][y1] ++;
		arr[x2 + 1][y1] --;
		arr[x1][y2 + 1] --;
		arr[x2 + 1][y2 + 1] ++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << arr[i][j] % 2;
//		cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
