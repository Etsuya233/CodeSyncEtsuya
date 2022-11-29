#include <stdio.h>
int main(){
	int rab=0,tur=0,cnt=0,cnt30=0,t=0,tt;
	scanf("%d",&tt);
	while(t<tt){
		if(t>0&&t%10==0){
			if(rab<=tur){
				t++;
				tur+=3;
				rab+=9;
				continue;
			}else{
				for(cnt30=0;cnt30<30&&t<tt;cnt30++){
					t++;
					tur+=3;
				}
				continue;
			}
		}
		tur+=3;
		rab+=9;
		t++;
	}
	if(rab>tur){
		printf("^_^ %d",rab);
	}else if(rab<tur){
		printf("@_@ %d",tur);
	}else{
		printf("-_- %d",rab);
	}
	
	
	
	return 0;
}
