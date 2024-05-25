#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    scanf("%lld", &n);
    n /= 1000;
    int s = n % 60;
    n /= 60;
    int m = n % 60;
    n /= 60;
    int h = n % 24;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}