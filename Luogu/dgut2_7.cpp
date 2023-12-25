#include <iostream>
using namespace std;

typedef long long ll;

typedef struct Matrix {
    ll arr[3][3];
} ma;

ma base = {
	1, 1, 1,
	1, 0, 0,
	0, 1, 0
};

ma me = {
	1, 0, 0,
	0, 1, 0,
	0, 0, 1
};

ma binaryPow(ma a, ll k);
ma multi(ma a, ma b);
int moda = (int)1e9 + 7;
//int testcnt = 0;

// Paimen Sequense
int main() {
    ll n;
    cin >> n;
    ll res = 0;
    if(n == 1 || n == 2 || n == 3) res = 1;
    else {
		ma m = binaryPow(base, n - 3);
    	res = (((m.arr[0][0] + m.arr[0][1]) % moda) + m.arr[0][2]) % moda;
	}
    cout << res << "\n";
    return 0;
}

ma multi(ma a, ma b) {
    ma ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.arr[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                ret.arr[i][j] = (ret.arr[i][j] + (a.arr[i][k] * b.arr[k][j]) % moda) % moda;
            }
        }
    }
    return ret;
}

ma binaryPow(ma a, ll k) {
//	testcnt++;
    if (k == 1) return a;
    if (k == 0) return me;
    if (k % 2 == 0) {
        ma mul = binaryPow(a, k / 2);
        return multi(mul, mul);
    } else {
        return multi(a, binaryPow(a, k - 1));
    }
}

