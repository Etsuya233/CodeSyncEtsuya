#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;
    while (count < 937) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }
    cout << "937是从2开始的第" << count << "个质数。" << endl;
    return 0;
}
