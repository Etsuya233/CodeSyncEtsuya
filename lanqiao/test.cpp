#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[10] = {0, 1, 2, 3, 0};
    int a = upper_bound(arr + 1, arr + 1 + 3, 3) - arr;
    cout << a;
}