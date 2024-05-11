#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //42300 21600
    for(int s = 0; s <= 6; s++){
        for(int f = 0; f <= 59; f++){
            for(int m = 0; m < 59; m++){
                double ps = s * 3600 + f * 60 + m;
                double pf = 720 * f + 12 * m;
                double pm = 720 * m;
                double a = abs(ps - pf);
                double b = abs(pf - pm);
                if(a > 21600) a = 43200 - a;
                if(b > 21600) b = 43200 - b;
                if(a == 0 || b == 0) continue;
                if(a == 2 * b){
                    cout << s << " " << f << " " << m << "\n";
                    return 0;
                }
            }
        }
    }


}