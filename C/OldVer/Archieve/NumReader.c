#include <stdio.h>
int main(){
	
	int num,tln,antix,numa,y,w,g;
	scanf("%d",&num);
	numa=num;
	
	g=numa%10000;
	numa/=10000;
	w=numa%10000;
	numa/=10000;
	y=numa%10000;
	if(y>0){
		num=y;
	do {
		tln = num % 10;
		num /= 10;
		antix = antix *  10 + tln; 
	} while (num != 0);
	//Up is num to antinum
	int cnt=0;
	tln=0;
	do{
		tln=antix%10;
		antix/=10;
		if(tln!=0){
			printf("%d",tln);
			cnt++;
		}else{
			printf("0");
			cnt++;
			while(antix%10==0){
				cnt++;
				antix/=10;
				continue;
			}
			continue;
		}
		switch(cnt){
		case 1:
			printf("qian");
			break;
		case 2:
			printf("bai");
			break;
		case 3:
			printf("shi");
			break;
		}
	}while(antix!=0);
	printf("YI");
	}
	if(w>0){
		num=w;
		do {
			tln = num % 10;
			num /= 10;
			antix = antix *  10 + tln; 
		} while (num != 0);
		//Up is num to antinum
		int cnt=0;
		tln=0;
		do{
			tln=antix%10;
			antix/=10;
			if(tln!=0){
				printf("%d",tln);
				cnt++;
			}else{
				printf("0");
				cnt++;
				while(antix%10==0){
					cnt++;
					antix/=10;
					continue;
				}
				continue;
			}
			switch(cnt){
			case 1:
				printf("qian");
				break;
			case 2:
				printf("bai");
				break;
			case 3:
				printf("shi");
				break;
			}
		}while(antix!=0);
		printf("WAN");
	}
	if(g>0){
		num=g;
		do {
			tln = num % 10;
			num /= 10;
			antix = antix *  10 + tln; 
		} while (num != 0);
		//Up is num to antinum
		int cnt=0;
		tln=0;
		do{
			tln=antix%10;
			antix/=10;
			if(tln!=0){
				printf("%d",tln);
				cnt++;
			}else{
				printf("0");
				cnt++;
				while(antix%10==0){
					cnt++;
					antix/=10;
				}
				continue;
			}
			switch(cnt){
			case 1:
				printf("qian");
				break;
			case 2:
				printf("bai");
				break;
			case 3:
				printf("shi");
				break;
			}
		}while(antix!=0);
	}
	return 0;
}
