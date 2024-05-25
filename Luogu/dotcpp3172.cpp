#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll s1 = (x2 - x1) * (y2 - y1);
	ll s2 = (x4 - x3) * (y4 - y3);
	ll top = min(y4, y2), bottom = max(y3, y1), left = max(x1, x3), right = min(x2, x4);
	ll co = 0;
	if(top > bottom && right > left){
		co = (top - bottom) * (right - left);
	}
	cout << s1 + s2 - co << "\n" ;
	return 0;;
}
