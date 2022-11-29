#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct gastation{
	double P;
	double D;
} gastation;

bool cmpGastationDist(gastation a, gastation b);
bool cmpGastationPrice(gastation a, gastation b);

int main(){
	double Cmax, D, Davg;
	int N;
	cin >> Cmax >> D >> Davg >> N;
	gastation trip[N];
	
	for(int i = 0; i < N; i++){	
		cin >> trip[i].P >> trip[i].D;
	}
	
	sort(trip, trip + N, cmpGastationDist);
	
	double currentC = 0, fee = 0, Dmax = Cmax * Davg, currentD = 0;
	int here = 0;
	if(trip[0].D != 0){
		cout << "The maximum travel distance = 0" << endl;
	} else {
		while(currentD < D){
			if(here == N - 1){
				if(Dmax < D - currentD) cout << "The maximun travel distance = " << currentD + Dmax;
				if(currentC < (D - currentC) * Davg){
					fee += (D - currentD) * trip[N - 1].P;
					break;
				}
			}
			if(Dmax < trip[here + 1].D - trip[here].D){
				currentD += Dmax;
				cout << "The maxinum travel distance = " << currentD;
			} else {
				if(trip[here].P < trip[here + 1].P){
					currentD = trip[here + 1].D;
					fee += (Cmax - currentC) * trip[here].P;
					currentC = Cmax;
				} else {
					currentD = trip[here + 1].D;
					fee += (trip[here + 1].D - trip[here].D) * Davg * trip[here].P;
					currentC = (trip[here + 1].D - trip[here].D) * Davg;
				}
			}
			here ++;
		}
	}
	
	cout << fee;
}

bool cmpGastationDist(gastation a, gastation b){
	return a.D < b.D;
}


bool cmpGastationPrice(gastation a, gastation b){
	return a.P < b.P;
}

//		gastation nearby[N];
//		int amount = 0;
//		for(int i = here; trip[i].D <= Dmax; i++){
//			nearby[i] = trip[i];
//			amount ++;
//		}
//		sort(nearby, nearby + amount, cmpGastationDist);
//		
//		for(int i = 0 ; i < amount; i++){
//			if(trip[here].P < nearby[i + 1].P){
//				fee += (Cmax - currentC) * trip[here].P;
//				canD = currentC / Davg;
//			} else {
//				
//			}
//	
