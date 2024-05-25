#include <iostream> 
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, np = 4, nsum = 3, cnt = 0;
queue<pll> qu;

int main(){
	cin >> n;
	qu.push({3, 2});
	while(np <= n && !qu.empty()){
		pll now = qu.front();
		qu.pop();
		for(int j = 0; j < now.second && np + j <= 1e9 + 10; j++){
			qu.push({np + j, now.first});
		}
		np += now.second;
	}
	pll now = qu.front();
	cout << now.first - 1 << "\n";
	return 0;
}
