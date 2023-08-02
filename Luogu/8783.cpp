#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define mem(a, m) memset(a, m, sizeof(a));
using namespace std;

ll n, m, k, ans=0;
int a[505][505];
int s[505][505];

int get_sum(int rx, int ry, int lx, int ly){
	return s[rx][ry]-s[rx][ly-1]-s[lx-1][ry]+s[lx-1][ly-1];
}
int main(){
	ios::sync_with_stdio(false);
	mem(s, 0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
		}
	}
	int up, dn;
	int le, ri;
	for(up=1;up<=n;up++){
		for(dn=up;dn<=n;dn++){
			for(le=1, ri=1;ri<=m;ri++){
				while(le <= ri && get_sum(dn, ri, up, le) > k)	le++;
				if(le <= ri)	ans+=ri-le+1;
			}
		}
	}
	cout << ans;
	return 0;
}
