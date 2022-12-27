#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct coin{
	int weight;
	int sum;
	double price;
} Coin;

bool cmpPrice(Coin a, Coin b);

int main(){
	int N, T;
	double sum = 0;
	scanf("%d%d", &N, &T);
	Coin arr[100];
	for(int i = 0; i < N; i++){
		scanf("%d%d", &arr[i].weight, &arr[i].sum);
		arr[i].price = 1.0 * arr[i].sum / arr[i].weight;
	}
	sort(arr, arr + N, cmpPrice);
	for(int i = 0; i < N; i++){
		if(T < 0) break;
		if(T < arr[i].weight){
			sum += 1.0 * arr[i].price * T;
			break;
		} else {
			sum += arr[i].sum;
			T -= arr[i].weight;
		}
	}
	printf("%.2f", sum);
}

bool cmpPrice(Coin a, Coin b){
	if(a.price >= b.price) return true;
	return false;
}
