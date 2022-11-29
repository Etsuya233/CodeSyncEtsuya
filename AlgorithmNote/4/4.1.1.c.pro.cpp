#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct gastation{
	double P;
	double D;
} gastation;

bool cmpGastationDist(gastation a, gastation b);
bool cmpGastationPrice(gastation a, gastation b);
void maxDistance(double X);

int main(){
	double Cmax, D, Davg;
	int N;
	cin >> Cmax >> D >> Davg >> N;
	gastation trip[N];
	
	for(int i = 0; i < N; i++){	
		cin >> trip[i].P >> trip[i].D;
	}
	
	sort(trip, trip + N, cmpGastationDist);
	
	double currentD = 0, currentC = 0, Dmax = Cmax * Davg, fee = 0;
	int here = 0;
	while(currentD < D){
		if(here == N - 1){
			cout << (D - trip[N - 1].D) / Davg  << endl;
			if(Dmax >= D - trip[N - 1].D){
				fee += (D - trip[N - 1].D) / Davg * trip[N - 1].P;
				currentD = D;
				break;
			} else {
				maxDistance(currentD + Dmax);
				break;
			}
		}
		
		if(Dmax >= trip[here + 1].D - trip[here].D){
			if(trip[here].P < trip[here + 1].P){
				fee += (Cmax - currentC) * trip[here].P;
				currentC = Cmax - (trip[here + 1].D - trip[here].D) / Davg;
			} else {
				double CINeed = (trip[here + 1].D - trip[here].D) / Davg;
				if(currentC < CINeed){
					fee += (CINeed - currentC) * trip[here].P;
					currentC = 0;
				} else {
					currentC -= CINeed;
//					cout << "currentC = " << currentC << ", CINeed = " << CINeed << endl;
				}
			}
			currentD = trip[here + 1].D;
			cout << "currentD = " << currentD << ", currentC = " << currentC << endl;
			here ++;
		} else {
			maxDistance(currentD + Dmax);
			break;
		}
		cout << fee << endl;
	}
	cout << fee;
}

bool cmpGastationDist(gastation a, gastation b){
	return a.D < b.D;
}

bool cmpGastationPrice(gastation a, gastation b){
	return a.P < b.P;
}

void maxDistance(double X){
	cout << "The maximum travel distance = " << X << endl;
}
