#include <iostream>
#include <string>
using namespace std;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(string a){
	for(int i = 0; i <= 5; i++){
		char d = a[i], b = a[i + 1], c = a[i + 2];
		if(b == d + 1 && c == b + 1) return true;
	}
	return false;
}

int main(){
	int ans = 0;
	for(int i = 1; i <= 12; i++){
		for(int j = 1; j <= month[i]; j++){
			string need2Check = "2022";
			string m = "";
			string d = "";
			if(i < 10) m = "0" + to_string(i);
			else m = to_string(i);
			if(j < 10) d = "0" + to_string(j);
			else d = to_string(j);
			need2Check += m + d;
			if(check(need2Check)) ans++;
		}
	}
	cout << ans;
}

