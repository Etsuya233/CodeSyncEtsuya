#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[100004];
int arr[26][100005] = {0};
int len = 0;
int ans = 0;

int main(){
	cin >> str;
	len = strlen(str);
	//pre
	for(int i = 0; i < len; i++){
		arr[str[i] - 'a'][++arr[str[i] - 'a'][0]] = i;
	}
	//travel
	for(int i = 0; i < 26; i++){
		for(int j = 1; j <= arr[i][0]; j++){
			int a = arr[i][j];
			int l = (j == 1)? 0: arr[i][j - 1] + 1;
			int r = (j == arr[i][0])? len - 1: arr[i][j + 1] - 1;
			ans += (a - l + 1) * (r - a + 1);
		}
	}
	//cout
	cout << ans << "\n";
} 
