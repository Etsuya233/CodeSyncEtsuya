#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "25", // 双引号中替换为 A 题的答案
        "1903", // 双引号中替换为 B 题的答案
        "1029", // 双引号中替换为 C 题的答案
        "1010", // 双引号中替换为 D 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}