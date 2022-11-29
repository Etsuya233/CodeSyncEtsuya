#include <cstdio>
#include <algorithm>
using namespace std;

int finger, counta = 0;
//int numberHash[10001] = {0};
int plusNumber;
int data[10001] = {0};
//int storage[10001] = {0};

void deal(int left);

int main(){
//	scanf("%d%d", &finger, &plusNumber);
//	for(int i = 1 ; i <= finger; i++) scanf("%d", &data[i]);
//	deal(finger);
//	return 0;

	scanf("%d%d", &finger, &plusNumber);
	for(int i = 1 ; i <= finger; i++) scanf("%d", &data[i]);
	do{
		counta++;
		if(counta == plusNumber + 1) break;
	} while(next_permutation(data + 1, data + finger + 1));
	
	for(int i = 1; i <= finger; i++){
		printf("%d", data[i]);
		if(i != finger) printf(" ");
	}
}

//void deal(int left){
//	if(left == 0){
//		counta++;
//		if(counta == plusNumber){
//			for(int i = finger; i > 0; i--){
//				printf("%d", storage[i]);
//				if(i != 1) printf(" ");
//			}
//		}
//	} else {
//		for(int i = 1; i <= finger; i++){
//			
//			if(numberHash[i]) continue;
//			numberHash[i] = 1;
//			storage[left] = i;
//			deal(left - 1);
//			numberHash[i] = 0;
//		}
//	}
//}
