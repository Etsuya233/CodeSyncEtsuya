#include <cstdio>

int main(){
	int o, p, q;
	scanf("%d%d%d", &o, &p, &q);
	int cnt = 0;
	for(int i = 123456789; i < 400000000; i++){
		int numberHash[10] = {0};
		int temp = i, a, b, c;
		c = temp % 1000;
		temp /= 1000;
		b = temp % 1000;
		temp /= 1000;
		a = temp;
		
		if(a < b && b < c){
			if(o * b == p * a && o * c == q * a){
				int temp2 = i;
				while(temp2 > 0){
					int digit = temp2 % 10;
					if(numberHash[digit]) break;
					numberHash[digit] ++;
					temp2 /= 10;
				}
				if(temp2 > 0) continue;
				else{
					printf("%d %d %d\n", a, b, c);
					cnt++;
				}
			} else continue;
		} else {
			continue;
		}
	}
	if(cnt == 0) printf("No!!!");
	
	
	return 0;
}
