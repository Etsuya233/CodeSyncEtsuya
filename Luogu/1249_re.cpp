#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r;
vector<int> nums;
int res[100000] = {1};
int digit = 1;

int main(){
	cin >> n;
	if(n == 3){
		cout << "1 2\n2";
		return 0;
	}
	if(n == 4){
		cout << "1 3\n3";
		return 0;
	}
	bool flag = false;
	while(n >= 3){
		if(n == 4){
			if(flag){
				nums.push_back(3);
				nums.push_back(1);
				break;
			} else {
				break;
			}
		} else if(n == 3){
			if(flag){
				nums.push_back(2);
				nums.push_back(1);
				break;
			} else {
				break;
			}
		} else {
			if(n % 2){
				flag = false;
				nums.push_back(n / 2 + 1);
				n /= 2;
			} else {
				flag = true;
				nums.push_back(n / 2);
				n /= 2;
			}
		}
	}
	if(n != 4 || n != 3) nums.push_back(n);
	int size = nums.size();
	for(int i = size - 1; i >= 0; i--){
		cout << nums[i] << " ";
	}
	cout << "\n";
	//multiply
	for(int i = size - 1; i >= 0; i--){
		for(int j = 0; j < digit; j++){
			res[i] *= nums[i];
		}
		int carry = 0;
		for(int j = 0; j < digit; j++){
			carry = res[i] / 10;
			res[i] %= 10;
		}
		while(carry > 0){
			res[digit++] = carry % 10;
			carry /= 10;
		}
	}
	for(int i = digit - 1; i >= 0; i--){
		cout << res[i];
	}
	return 0;
}
