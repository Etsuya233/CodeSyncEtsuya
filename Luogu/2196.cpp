#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node{
	int ret = 0;
	int amount;
	int kids = 0;
	int next[19] = {0};
	int bestNext = 0;
} node;

int n;
node arr[21];
int opera(int i);

int main(){
	cin >> n;
    //Input
	for(int i = 1; i <= n; i++) cin >> arr[i].amount;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			int a;
			cin >> a;
			if(a) arr[i].next[arr[i].kids++] = j;
		}
	}
    //Calc
	for(int i = 1; i <= n; i++){
		opera(i);
	}
	//Stats
	int maxLoc = 0, maxAns = 0;
	for(int i = 1; i <= n; i++){
		if(arr[i].ret > maxAns){
			maxLoc = i;
			maxAns = arr[i].ret;
		}
	}
    //Output
	int loc = maxLoc;
	while(arr[loc].kids != 0){
		cout << loc << " ";
		loc = arr[loc].next[arr[loc].bestNext];
	}
	cout << loc << "\n" << maxAns;
}

int opera(int i){
	if(arr[i].kids == 0){
		return arr[i].ret = arr[i].amount;
	}
	if(arr[i].ret > 0) return arr[i].ret;
	else {
		int temp;
		for(int j = 0; j < arr[i].kids; j++){
			temp = opera(arr[i].next[j]);
			if(temp > arr[i].ret){
				arr[i].bestNext = j;
				arr[i].ret = temp;
			}
		}
		arr[i].ret += arr[i].amount;
		return arr[i].ret;
	}
}