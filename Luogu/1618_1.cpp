#include <cstdio>

int main(){
	int o, p, q, cnt = 0;
	scanf("%d%d%d", &o, &p, &q);
	int numberHash[10] = {0};
	for(int a = 1; a <= 9; a++){
		numberHash[a] = 1;
		for(int b = 1; b <= 9; b++){
			if(numberHash[b]) continue;
			numberHash[b] = 1;
			for(int c = 1; c <= 9; c++){
				if(numberHash[c]) continue;
				numberHash[c] = 1;
				for(int d = 1; d <= 9; d++){
					if(numberHash[d]) continue;
					numberHash[d] = 1;
					for(int e = 1; e <= 9; e++){
						if(numberHash[e]) continue;
						numberHash[e] = 1;
						for(int f = 1; f <= 9; f++){
							if(numberHash[f]) continue;
							numberHash[f] = 1;
							for(int g = 1; g <= 9; g++){
								if(numberHash[g]) continue;
								numberHash[g] = 1;
								for(int h = 1; h <= 9; h++){
									if(numberHash[h]) continue;
									numberHash[h] = 1;
									for(int i = 1; i <= 9; i++){
										if(numberHash[i]) continue;
										int ret1 = a * 100 + b * 10 + c;
										int ret2 = d * 100 + e * 10 + f;
										int ret3 = g * 100 + h * 10 + i;
										if(ret1 * p == ret2 * o && ret1 * q == ret3 * o){
											cnt++;
											printf("%d %d %d\n", ret1, ret2, ret3);
										}
									}
									numberHash[h] = 0;
								}
								numberHash[g] = 0;
							}
							numberHash[f] = 0;
						}
						numberHash[e] = 0;
					}
					numberHash[d] = 0;
				}
				numberHash[c] = 0;
			}
			numberHash[b] = 0;
		}
		numberHash[a] = 0;
	}
	if(cnt == 0) printf("No!!!");
	return 0;
}
