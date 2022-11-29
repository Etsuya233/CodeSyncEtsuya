#include <stdio.h>
#include <string.h>
int main(void){
	int body,n;
	scanf("%d %d", &body,&n);
	int p;
	p=n;
	
	int result[100002]={0};
	int time,digit,plus=0;
	
	if (n==0){
		printf("0");
	}else{
	int cnt;
		for(;p>0;p--,cnt++){
			time=body*p;
			result[cnt]=(plus+time)%10;
			plus=(plus+time)/10;
	//		printf("time=%d\tresult[%d]=%d\tplus=%d\n",time,cnt,result[cnt],plus);
		}
	}
	
//	printf("%d",result[1]);
	n-=1;
	for(;n>=0;n--){
		printf("%d",result[n]);
	}
}
