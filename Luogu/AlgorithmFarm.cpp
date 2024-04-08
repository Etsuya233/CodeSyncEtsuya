#include <iostream>
#include <cmath>
using namespace std;

//Prime Number
int primeNumber[1000];
void findPrime(int num);

//GCD and LCM
int gcd(int a, int b);

//Prime Factor
typedef struct PrimeFactorNode{
	int x, cnt = 0;
} pfactor;
void numPrimeFactor(int num);


int main(){
	findPrime(200);
	numPrimeFactor(22);
	
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

void findPrime(int num){
	int vis[num + 2] = {0};
	primeNumber[0] = 0;
	for(int i = 2; i <= num; i++){
		if(!vis[i]){
			primeNumber[++primeNumber[0]] = i;

		}
		for(int j = 1; j <= primeNumber[0] && primeNumber[j] * i <= num; j++){
			vis[primeNumber[j] * i] = 1;
			if(i % primeNumber[j] == 0) break; //avoid repeat calculation
		}
	}
}

void numPrimeFactor(int num){
	pfactor fac[30]; //storage the factors
	int now = num; 
	int cnt = 0;
	for(int i = 1; primeNumber[i] <= sqrt(num); i++){ //all the prime factors that less or equal to sqrt(num)
		if(now % primeNumber[i] == 0){
			fac[cnt].x = primeNumber[i];
			fac[cnt].cnt = 0;
			while(now % primeNumber[i] == 0){
				fac[cnt].cnt ++;
				now /= primeNumber[i];
			}
			cnt++;
		}
		if(now == 1) break;
	}
	if(now != 1){ //if theres a prime factor which is greater than sqrt(num)
		fac[cnt].x = now;
		fac[cnt].cnt = 1;
		cnt++;
	}
	
	for(int i = 0; i < cnt; i++){
		cout << fac[i].x << " " << fac[i].cnt << "\n";
	}
}
