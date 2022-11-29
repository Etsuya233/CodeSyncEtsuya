#include <cstdio>
#include <cstring>
#include <cstdlib>

char fold[20005];
char unfold[20005];

char* func(int loc);

int main(){
	scanf("%s", fold);
	for(int i = 0; fold[i] != '\0'; i++){
		if(fold[i] != '[') printf("%c", fold[i]);
		else{
			char* the_return = func(i);
			printf("%s", the_return);
			free(the_return);
			//Skip the folded area
			
		}
	}
	
	
}

char* func(int loc){
	//Maybe it needs malloc!!
	//Read Number
	loc++;
	int multiplier = 0;
	while(fold[loc] >= '0' && fold[loc] <= '9'){
		multiplier * 10 + fold[loc] - '0';
		loc++;
	}
	//Read the repetitive string
	char repeat[5000] = ""; 
	if(fold[loc] == '['){
		char* the_return = func(loc);
		strcpy(repeat, the_return);
		free(the_return);
	} else {
		int temp = 0;
		while(fold[loc] != ']'){
			repeat[temp] = fold[loc];
			temp++;
			loc++;
		}
		repeat[temp] = '\0';
	}
	//Unfold the string
	char* repeat_unfold_1 = (char*)malloc(sizeof(char) * 10000);
	repeat_unfold_1[0] = '\0';
	int temp = 0;
	for(int i = 0; i < multiplier; i++){
		strcat(repeat_unfold_1, repeat);
	}
	return repeat_unfold_1;
}
