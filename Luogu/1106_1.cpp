#include <string>
#include <iostream>
using namespace std;

int main(){
	string num;
	int n;
	cin >> num >> n;
	
	//Stage 1 -> 先使数列单调
	int hasMax = 1;
	while(hasMax){
		hasMax = 0;
		for(int i = 1; i < num.size(); i++){
			if(num[i - 1] > num[i]){
				if(n <= 0) break;
				num.erase(i - 1, 1);
				n --;
				hasMax = 1;
				break;
			}
		}
		if(n <= 0) break;
	}
	//Stage 2 -> 从后往前删除
	while(n > 0){
		num.erase(num.size() - 1, 1);
		n --;
	}
	//Delete the zero on the front
	if(num[0] == '0'){
		while(num[0] == '0'){
			num.erase(0, 1);
		}
	}
	//Print
	if(num.size() == 0) cout << 0;
	else cout << num;
	return 0;
}
