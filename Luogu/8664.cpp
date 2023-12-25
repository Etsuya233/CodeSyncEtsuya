#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double lb;

int n;
lb amount;
int arr[500005] = {0};

int main(){
	scanf("%d %Lf", &n, &amount);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	lb leftm = amount;
	lb avg = 1.0 * amount / n;
	lb q = 0;
	lb z;
	for(int i = 1; i <= n; i++){
		lb need = leftm / (n - i + 1.0);
		z = min(1.0l * arr[i], need);
		leftm -= z;
		q += (z - avg) * (z - avg);
	}
	printf("%.4Lf", sqrt(q / n));
	return 0;
}
