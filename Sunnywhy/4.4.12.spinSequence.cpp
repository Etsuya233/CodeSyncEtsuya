#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int search;
	scanf("%d", &search);
	int data[n];
	for(int i = 0; i < n; i++) scanf("%d", &data[i]);
	
	// algotithm
	int l = 0, r = n - 1, half, flag = 0;
	while(l <= r){
		half = (l + r) / 2;
		if(data[half] == search){
			printf("%d", half);
			flag = 1;
			break;
		} else if(search >= data[half] && search <= data[r]) l = half + 1;
		else r = half - 1;
	}
	if(!flag) printf("-1");
}
