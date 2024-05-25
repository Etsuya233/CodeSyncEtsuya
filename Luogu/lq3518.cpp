#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct {
    ll x, y, z;
} koto;

koto arr[100005];
koto tempa;
int n;

bool cmpX(koto a, koto b);
bool cmpY(koto a, koto b);
bool cmpZ(koto a, koto b);

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
    ll minAns = 1000000;
    ll ans = 0;
    ll now = 0;
    ll sum = 0;
    sort(arr + 1, arr + 1 + n, cmpX);
    for(int i = 1; i <= n; i++){
        if(sum + arr[i].x - arr[i].y - arr[i].z > 0) sum += arr[i].x - arr[i].y - arr[i].z;
        else break;
        now++;
    }
    ans = max(ans, now);
    minAns = min(ans, now);
    now = 0;
    sum = 0;
    sort(arr + 1, arr + 1 + n, cmpY);
    for(int i = 1; i <= n; i++){
        if(sum + arr[i].y - arr[i].x - arr[i].z > 0) sum += arr[i].y - arr[i].x - arr[i].z;
        else break;
        now++;
    }
    ans = max(ans, now);
    minAns = min(ans, now);
    now = 0;
    sum = 0;
    sort(arr + 1, arr + 1 + n, cmpZ);
    for(int i = 1; i <= n; i++){
        if(sum + arr[i].z - arr[i].x - arr[i].y > 0) sum += arr[i].z - arr[i].x - arr[i].y;
        else break;
        now++;
    }
    ans = max(ans, now);
    minAns = min(ans, now);
    if(ans == 0) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
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