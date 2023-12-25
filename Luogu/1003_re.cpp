#include <iostream>
using namespace std;

typedef struct Blanket{
	int x1, y1, x2, y2;
} bl;

bl arr[100050];
int n;
int a, b;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
		arr[i].x2 += arr[i].x1;
		arr[i].y2 += arr[i].y1;
	}
	cin >> a >> b;
	int ans = -1;
	for(int i = 0; i <= n; i++){
		if(a >= arr[i].x1 && a <= arr[i].x2 && b >= arr[i].y1 && b <= arr[i].y2){
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
