#include <stdio.h>
int main(){
	int formula[101][2];
	int cnt=0,power,number;
	
	int a=0,b=0;	//初始化数组
	for(;a<101;a++){
		formula[a][1]=0;
	}
	
	printf("请输入（幂 系数）：");//输入幂及系数，并完成对0次幂的处理
	while(cnt<2){
		scanf("%d %d",&power,&number);
		if(power!=0){
			formula[power][0]+=power;
			formula[power][1]+=number;
		}else{
			cnt++;
		}
	}
	
	int plus=0;//输出 plus用来判断加号
	power=100;
	while(power>0){
		if(formula[power][1]!=0){
			if(plus==1){
				printf("+");
			}
			printf("%dx%d", formula[power][1], power);
			plus=1;
		}
		power--;
	}
	
	return 0;
}
