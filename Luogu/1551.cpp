#include <iostream>
using namespace std;

int n, m, p;
int parent[5002];

int find(int x);
int connected(int x, int y);
void unionthem(int x, int y);

int main(){
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        unionthem(a, b);
    }
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        if(connected(a, b)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

}

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int connected(int x, int y){
    int p1 = find(x), p2 = find(y);
    return p1 == p2;
}

void unionthem(int x, int y){
    int rootx = find(x), rooty = find(y);
    if(rootx == rooty){
        return;
    } else {
        parent[rootx] = rooty;
    }
}