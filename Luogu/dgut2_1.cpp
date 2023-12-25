#include <iostream>
#include <cstring>
using namespace std;

char str[100000];
char stdstr[10] = "fandian";
int n;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int i = 0; str[i] != '\0'; i++){
			if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		}
  		int a = strcmp(str, stdstr);
		if(a == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
