//什么垃圾题目
#include <cstdio>
#include <cstring>

int main(){
	char str[105];
	int matched[105] = {0};
	scanf("%s", str);
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ')'){
			for(int j = i - 1; j >= 0; j--){
				if(str[j] == '[' && matched[j] == 0){
					break;
				} else if(str[j] == '(' && matched[j] == 0){
					matched[j] = matched[i] = 1;
					break;
				}
			}
		}
		else if(str[i] == ']'){
			for(int j = i - 1; j >= 0; j--){
				if(str[j] == '(' && matched[j] == 0){
					break;
				} else if(str[j] == '[' && matched[j] == 0){
					matched[j] = matched[i] = 1;
				}
			}
		}
	}
	for(int i = 0; i < strlen(str); i++){
		if(matched[i]) printf("%c", str[i]);
		else {
			if(str[i] == '(' || str[i] == ')') printf("()");
			if(str[i] == '[' || str[i] == ']') printf("[]");
		}
	}
}