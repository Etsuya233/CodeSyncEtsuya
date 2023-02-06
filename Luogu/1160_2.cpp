#include <iostream>
using namespace std;

typedef struct Number{
	int left = 0;
	int right = 0;
} num;

int main(){
	int erased[100001] = {0};
	num arr[100001];
	arr[0].right = 1;
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int a, b;
		cin >> a >> b;
		if(b){
			int oriRight = arr[a].right;
			arr[a].right = i;
			arr[oriRight].left = i;
			arr[i].left = a;
			arr[i].right = oriRight;
		} else {
			int oriLeft = arr[a].left;
			arr[a].left = i;
			arr[oriLeft].right = i;
			arr[i].left = oriLeft;
			arr[i].right = a;
		}
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		if(erased[a]) continue;
		int oriLeft = arr[a].left;
		int oriRight = arr[a].right;
		arr[oriLeft].right = oriRight;
		arr[oriRight].left = oriLeft;
		erased[a] = 1;
	}
	int loc = arr[0].right;
	while(true){
		cout << loc << " ";
		loc = arr[loc].right;
		if(loc == 0){
			break;
		}
	}

}