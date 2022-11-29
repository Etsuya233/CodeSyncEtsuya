#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arrN[n];
	for(int i = 0; i < n; i++) cin >> arrN[i];
	int m;
	cin >> m;
	int arrM[m];
	for(int i = 0; i < m; i++) cin >> arrM[i];
	
	int i = 0, j = 0, k = 0;
	int sum[n + m];
	while(i < n && j < m){
		if(arrN[i] > arrM[j]){
			sum[k++] = arrM[j++];
		} else {
			sum[k++] = arrN[i++];
		}
	}
	while(i < n) for(; i < n; i++) sum[k++] = arrN[i++];
	while(j < n) for(; j < m; j++) sum[k++] = arrM[j++];
	
	for(int q = 0; q < n + m; q ++){
		cout << sum[q] << " ";
	}
	
	
}
