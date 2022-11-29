#include <stdio.h>
void read(int reada);
int main(){
	int num[9]={0};
	int number=0;
	scanf("%d", &number);
	int cnt=0;
	for(cnt=0;number>0;cnt++){	//把数字倒序地输入到数组中
		num[cnt]=number%10;
		number/=10;
	}
//	int maxdigit=8;	//把叔祖里的数字全部推到最右边
//	for(;cnt>0;cnt--){
//		num[maxdigit]=num[cnt];
//		maxdigit--;
//	}
	cnt-=1;	//cnt多了
	for(;cnt>=0;cnt--){	//开始读数字
		if(num[cnt]>0){
			int reada=num[cnt];
			read(reada);
//			printf(" %d ", num[cnt]);
			if(cnt==3 || cnt==7){
				printf("千");
			}else if(cnt==2 || cnt==6){
				printf("百");
			}else if(cnt==1 || cnt==5){
				printf("十");
			}
		}else{
			if((num[cnt+1]!=0&&cnt!=4&&cnt!=0)||cnt==3){	//这一步处理0的读法，太麻烦了
				printf("零");
			}
		}
		if(cnt==8){
			printf("亿");
		}else if(cnt==4){
			printf("万");
		}
		
	}

	
//	{
//		for(int a=0;a<9;a++){
//			printf("%d",num[a]);
//		}
//	}
	
	return 0;
}
void read(int reada){
	switch(reada){
	case 1:
		printf("一");
		break;
	case 2:
		printf("二");
		break;
	case 3:
		printf("三");
		break;
	case 4:
		printf("四");
		break;
	case 5:
		printf("五");
		break;	
	case 6:
		printf("六");
		break;
	case 7:
		printf("七");
		break;
	case 8:
		printf("八");
		break;
	case 9:
		printf("九");
		break;
	}
}
