#include <cstdio>
#include <set>
using namespace std;

int main(){
	set<int> s;
	s.insert(2);
	s.insert(4);
	s.insert(3);
	
	set<int>::iterator sp = s.begin();
	printf("%d", *sp);
	sp++;
}
