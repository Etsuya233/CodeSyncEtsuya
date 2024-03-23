#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int age1, age2, id1 = 1, id2 = 2, li1, li2;
    cin >> li1 >> li2 >> age1 >> age2;
    if(age1 > age2){
        swap(age1, age2);
        swap(id1, id2);
    }
    if(age1 < li1 && age2 >= li2){
        if(id1 < id2){
            cout << age1 << "-Y " << age2 << "-Y\n";
        } else {
            cout << age2 << "-Y " << age1 << "-Y\n";
        }
        cout << "qing " << id2 << " zhao gu hao " << id1 << "\n";
    } else if(age1 >= li1 && age2 >= li1){
        if(id1 < id2){
            cout << age1 << "-Y " << age2 << "-Y\n";
        } else {
            cout << age2 << "-Y " << age1 << "-Y\n";
        }
        cout << "huan ying ru guan\n";
    } else if(age1 < li1 && age2 < li1){
        if(id1 < id2){
            cout << age1 << "-N " << age2 << "-N\n";
        } else {
            cout << age2 << "-N " << age1 << "-N\n";
        }
        cout << "zhang da zai lai ba\n";
    } else {
        if(id1 < id2){
            cout << age1 << "-N " << age2 << "-Y\n";
        } else {
            cout << age2 << "-Y " << age1 << "-N\n";
        }
        cout << id2 << ": huan ying ru guan\n";
    }
    return 0;
}