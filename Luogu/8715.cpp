#include <iostream>
#include <cstring>
using namespace std;

char str[100004];
int arr[100004][26] = {0};
int len = 0;
int ans = 0;

int main(){
	cin >> str;
	len = strlen(str);
	//pre
	for(int i = 0; i < len; i++){
		arr[i][str[i] - 'a'] = 1;
	}
	for(int i = 0; i < 26; i++){
		for(int j = 1; j < len; j++){
			arr[j][i] += arr[j - 1][i];
		}
	}
	//calc
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			for(int k = 0; k < 26; k++){
				if(arr[j][k] - ((i == 0)? 0: arr[i - 1][k]) == 1) ans++;
			}
		}
	}
	//cout
	cout << ans << "\n";
} 
