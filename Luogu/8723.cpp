#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> st;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            char m1 = (i < 10)? '0' + i: 'A' + (i - 10);
            char m2 = (j < 10)? '0' + j: 'A' + (j - 10);
            cout << m1 << "*" << m2 << "=";
            int ans = i * j;
            while(ans > 0){
                st.push(ans % n);
                ans /= n;
            }
            while(!st.empty()){
                int top = st.top();
                st.pop();
                char now = (top < 10)? '0' + top: 'A' + (top - 10);
                cout << now;
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}