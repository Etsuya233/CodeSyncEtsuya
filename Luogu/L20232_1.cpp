#include <iostream>
#include <cmath>
using namespace std;

//ans 11027424

int len = 23333333;
double res = 11625907.5798;

int main(){
	double val = 0x7fffffff;
	int ans = 0;
	for(int i = 1; i <= len / 2; i++){
		double ret = - (1.0 * i * i / len * (log2(i) - log2(len))) - 1.0 * (len - i) * (len - i) / len * (log2(len - i) - log2(len));
		if(i == 11027421) cout << ret << "\t" << fabs(res - ret) << "\n";
		if(fabs(res - ret) < val){
			val = fabs(res - ret);
			ans = i;
		}
	}
	cout << val << "\t" << ans;
}
