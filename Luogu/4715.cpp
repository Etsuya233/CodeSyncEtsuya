#include <cstdio>
#include <cmath>

int main(){
	int n, energy[130] = {0}, energy_copy[130] = {0};
	scanf("%d", &n);
	for(int i = 1; i <= pow(2, n); i++){
		scanf("%d", &energy[i]);
		energy_copy[i] = energy[i];
	}
	for(int i = n; i >= 2; i--){
		for(int j = 1; j <= pow(2, i - 1); j++){
			energy[j] = (energy[2 * j] > energy[2 * j - 1])? energy[2 * j]: energy[2 * j - 1];
		}
	}
	int ans = (energy[1] < energy[2])? energy[1]: energy[2];
	int loc = 1;
	while(true){
		if(energy_copy[loc] == ans) break;
        loc++;
	}
	printf("%d", loc);
}