#include <stdio.h>
int main(){
	double pi=1,aa=1.0,b=3.0,temp,a=1.0,cnt=0,limit;
	scanf("%lf",&limit);
	while(1){
		temp=a/b;
		pi+=temp;
		aa+=1;
		b*=(aa*2+1);
		a=1.0;
		for(cnt=0;cnt<aa;a*=cnt){
			cnt++;
		}
		if(temp<limit){
			break;
		}
	}
	printf("%.6f",2*pi);
	return 0;
}
