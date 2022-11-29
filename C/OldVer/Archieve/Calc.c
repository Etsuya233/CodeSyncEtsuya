#include <stdio.h>
int main(){
//	char a='0',temp;
//	int sum=0;
//	while ((a>47 && a<58)||a=='+'||a=='-'||a=='*'||a=='/'||a=='='){
//		if (a>47 && a<58){
//			sum=sum*10+(a-48);
//		} else if (a == '+'){
//			
//		}
//		scanf("%c",a);
//	}
//	printf("%d",&sum);
	
	char a = '0';
	int num;
	int sum =0;
	scanf("%d",&num);
	sum += num;
	do{
		scanf("%c",&a);
		if(a=='+'){
			scanf("%d", &num);
			sum += num;
		}else if(a=='-'){
			scanf("%d", &num);
			sum -= num;
		}else if(a=='*'){
			scanf("%d", &num);
			sum *= num;
		}else if(a=='/'){
			scanf("%d", &num);
			if(num==0){
				printf("ERROR!\n");
				break;
			}
			sum /= num;
		}else if((a!='+'||a!='-'||a!='*'||a!='/')&&a!='='){
			printf("ERROR!\n");
			break;
		}else if(a=='='){
			break;
		}
	} while(a!='=');
	printf("%d\n", sum);
	
	return 0;
}
