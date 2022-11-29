#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	stack<int> s;
	int x, nowMax = 0;
	bool isValid = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x > nowMax) {
			for (int j = nowMax + 1; j <= x; j++) {
				s.push(j);
			}
			nowMax = x;
		}
		if (s.top() != x) {
			isValid = false;
			break;
		} else {
			s.pop();
		}
	}
	printf(isValid ? "Yes" : "No");
	return 0;
}
