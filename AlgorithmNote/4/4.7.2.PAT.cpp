#include <cstdio>
#include <cstring>

int main(){
	char str[10000];
	gets(str);
	int length = strlen(str), result = 0;
	
	if(length <= 2){
		result = 0;
	} else {
		int p[10000] = {0};
		int t[10000] = {0};
		
		for(int i = 1; i < length; i++){
			if(str[i - 1] == 'P') p[i] = p[i - 1] + 1;
			else p[i] = p[i - 1];
		}
		for(int i = length - 1; i >= 0; i--){
			if(str[i + 1] == 'T') t[i] = t[i + 1] + 1;
			else t[i] = t[i + 1];
			if(str[i] == 'A') result += p[i] * t[i];
		}
		printf("%d", result);
	}
	
	return 0;
}
