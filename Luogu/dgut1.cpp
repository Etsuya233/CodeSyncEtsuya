#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	char str[(int)1e4 + 10];
	for(int i = 0; i < n; i++){
		cin >> str;
		int len = strlen(str);
		int j = 0;
		for( ; j < len; j++){
			if(str[j] == 'S' || str[j] == 's'){
				break;
			}
		}
		if(j >= len){
			cout << "NO\n";
		} else cout << "YES\n";
	}
	return 0;
}
