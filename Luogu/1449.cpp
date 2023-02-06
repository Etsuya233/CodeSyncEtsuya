#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> my;
    int number = 0;
    int ans = 0;
    while(true){
        char a;
        cin >> a;
        if(a >= '0' && a <= '9'){
            number = 10 * number + a - '0';
        } else if(a == '.'){
            my.push(number);
            number = 0;
        } else if(a == '@'){
            break;
        } else {
            int c = my.top();
            my.pop();
            int b = my.top();
            my.pop();
            switch(a){
            case '+':
                my.push(b + c);
                break;
            case '-':
                my.push(b - c);
                break;
            case '*':
                my.push(b * c);
                break;
            case '/':
                my.push(b / c);
                break;
            }
        }
    }
    cout << my.top();
}