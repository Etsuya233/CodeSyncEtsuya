#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmpSize(int a, int b);

int main(){
	while(true){
		int L, N;
		cin >> L >> N;
		int l[N];
		for(int i = 0; i < N; i++){
			cin >> l[i];
		}
		sort(l, l + N, cmpSize);
		for(int i = 0 ; i < N; i++){
			L -= l[i];
			if(L <= 0){
				cout << i + 1 << endl;
				break;
			}
		}
		if(L > 0) cout << "impossible\n";
	}
}

bool cmpSize(int a, int b){
	return a > b;
}
