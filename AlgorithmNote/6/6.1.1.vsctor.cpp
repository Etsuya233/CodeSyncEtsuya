#include <cstdio>
#include <vector>
using namespace std;

int main(){
	vector<int> v1;
	for(int i = 0; i < 5; i++) v1.push_back(i);
	vector<int>::iterator vp1 = v1.begin();
	v1.insert(vp1, 12);
	for(;vp1 <= v1.end() - 1; vp1++){
		printf("%d", *vp1);
	}	
	
}
