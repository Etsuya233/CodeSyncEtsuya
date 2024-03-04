#include <iostream>
#include <cstring>
using namespace std;

char str[100004];
int arr[26] = {0};
int len = 0;
int ans = 0;

int main(){
	cin >> str;
	len = strlen(str);
	//travel
	for(int i = 1; i <= len; i++){
		memset(arr, 0, sizeof(arr));
		for(int j = 0; j < i; j++){
			arr[str[j] - 'a']++;
		}
		int naka = 0;
		for(int j = 0; j < 26; j++){
			if(arr[j] == 1) naka++;
		}
		ans += naka;
		for(int j = 1; j + i - 1 < len; j++){
			int r = j + i - 1;
			if(++arr[str[r] - 'a'] == 1) naka += 1;
			if(arr[str[r] - 'a'] - 1 == 1) naka -= 1;
			if(--arr[str[j - 1] - 'a'] == 1) naka += 1;
			if(arr[str[j - 1] - 'a'] + 1 == 1) naka -= 1;
			ans += naka;
		}
	}
	//cout
	cout << ans << "\n";
} 
