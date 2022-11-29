#include <cstdio>
#include <cmath>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int stick[n];
	int maxStick = 0;	//To memory the maximum length of the stick
	for(int i = 0; i < n; i++){
		int length;
		scanf("%d", &length);
		stick[i] = length;
		maxStick = (length > maxStick)? length: maxStick;
	}
	
	int segment = 0, half, l = 0, r = maxStick;
	while(l < r){
		segment = 0;
		half = ceil(1.0 * (l + r) / 2);	//向上取整
		if(half == 0) break;
		for(int i = 0; i < n; i++) segment += stick[i] / half;
		if(segment >= k){
			l = half;
		} else {
			r = half - 1;
		}
	}
	
	if(l <= r){
		printf("%d", l);
	} else{
		printf("0");
	}
}
