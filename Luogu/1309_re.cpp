#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Competetor{
	int power, point, id;
} com;

com arr[200010];
int n, r, q;

bool cmpCom(com a, com b);

int main(){
	cin >> n >> r >> q;
	for(int i = 0; i < 2 * n; i++){
		arr[i].id = i + 1;
		cin >> arr[i].point;
	}
	for(int i = 0; i < 2 * n; i++){
		cin >> arr[i].power;
	}
	for(int k = 0; k < r; k++){
		sort(arr, arr + 2 * n, cmpCom);
		for(int i = 0; i < n; i++){
//			cout << 2 * i << "\n";
			if(arr[2 * i].power > arr[2 * i + 1].power){
				arr[2 * i].point ++;
			} else {
				arr[2 * i + 1].point ++;
			}
		}
	}
	sort(arr, arr + 2 * n, cmpCom);
	cout << arr[q - 1].id;
}

bool cmpCom(com a, com b){
	if(a.point > b.point) return true;
	else if(a.point == b.point && a.id < b.id) return true;
	return false;
}
