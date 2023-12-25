#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int ans = 0;


int main(){
	cin >> n >> k;
	if(k > n) k = k % n;
	int stdA = 0, stdB = 0, stdC = 0, temp = 0, fixA = 0, fixB = 0, nowAns = 0;
	for(int i = 1; i < n; i++){
		stdA = i / k;
		stdB = i % k;
		stdC = stdA + stdB;
		temp = i;
		while(true){
			temp += n;
			fixA = temp / k;
			fixB = temp % k;
			if(fixA + fixB < stdC){
				stdC = fixA + fixB;
				break;
			}
		}
		
		ans = max(ans, nowA + nowB);
	}
	cout << ans;
}
