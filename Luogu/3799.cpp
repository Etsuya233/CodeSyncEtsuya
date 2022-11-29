#include <cstdio>
#include <algorithm>
using namespace std;

long long C(long long n, long long m);
long long res[1000][100] = {0}; //To storage the result of function C
long long mod = 1e9 + 7;

int main(){
	long long sum = 0;
	long long n;
	scanf("%lld", &n);
	long long stick[n], numberHash[5005] = {0};
	for(long long i = 0; i < n; i++){
		long long num;
		scanf("%lld", &num);
		stick[i] = num;
		numberHash[num]++;
	}
	sort(stick, stick + n);
	
	//Algorithm
	for(long long i = 1; i < n; i += numberHash[stick[i]]){
//		printf("%lld\n", stick[i]);
		if(numberHash[stick[i]] > 1){
			for(long long j = 0, k = i - 1; j < k;){
//				if(stick[i] == 5){
//					printf("i = %lld, k = %lld\n", i, k);
//				}
				if(stick[j] + stick[k] == stick[i]){
					if(stick[j] == stick[k]){
						sum += C(numberHash[stick[i]], 2) * C(numberHash[stick[j]], 2) % mod;
					} else {
						sum += C(numberHash[stick[i]], 2) * numberHash[stick[j]] * numberHash[stick[k]] % mod;
					}
					j += numberHash[stick[j]];
					k -= numberHash[stick[k]];
				} else if(stick[j] + stick[k] > stick[i]){
					k--;
				} else if(stick[j] + stick[k] < stick[i]){
					j++;
				}
			}
//			printf("%.6lld   ", stick[i]);
//			printf("%lld\n", sum);
		}
	}
	printf("%lld", sum % mod);
	return 0;
}

long long C(long long n, long long m){
	if(n < m) return 1;
	if(m == 0 || m == n) return 1;
	if(res[n][m]) return res[n][m];
	return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % mod;
}
