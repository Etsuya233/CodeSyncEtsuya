#include <stdio.h>
int main(){
	int x, y, z, a;
	scanf("%d", &a);
	for( x = 0 ; x < 10 * a; x ++ ){
		for( y = 0; y < 5 *a; y ++ ){
			for( z = 0 ; z < 2 *a ; z ++){
				if( 0.1 * x + 0.2 * y + 0.5 * z == a){
					printf("%d %d %d --> %f\n", x, y, z, 0.1 * x + 0.2 * y + 0.5 * z);
				}
			}
		}
	}
	
	return 0;
}
