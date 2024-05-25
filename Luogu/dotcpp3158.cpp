#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Jiken{
    int x, y, z;
} koto;

koto arr[100005];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].x;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i].y;
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i].z;
    }
    sort(arr + 1, arr + 1 + n, cmpX);
    


}

bool cmpX(koto a, koto b){
    if(a.x - a.y - a.z != b.x - b.y - b.z) return a.x - a.y - a.z > b.x - b.y - b.z;
    else if(a.x != b.x) return a.x > b.x;
    else if(a.y != b.y) return a.y > b.y;
    else return a.z > b.z;
}

bool cmpY(koto a, koto b){
    if(a.y - a.x - a.z != b.y - b.x - b.z) return a.y - a.x - a.z > b.y - b.x - b.z;
    else if(a.y != b.y) return a.y > b.y;
    else if(a.x != b.x) return a.x > b.x;
    else return a.z > b.z;
}

bool cmpZ(koto a, koto b){
    if(a.z - a.x - a.y != b.z - b.x - b.y) return a.z - a.x - a.y > b.z - b.x - b.y;
    else if(a.z != b.z) return a.z > b.z;
    else if(a.y != b.y) return a.y > b.y;
    else return a.x > b.x;
}