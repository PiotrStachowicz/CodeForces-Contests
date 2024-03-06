//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
int t;


int main() {
    cin >> t;
    while(t--){
        long long int x0, x1, x2, y0, y1, y2;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        if(y0 == y1 && y2 < y1){
            cout << abs(x0 - x1) << endl;
        }else if(y0 == y2 && y1 < y2){
            cout << abs(x0 - x2) << endl;
        }else if(y1 == y2 && y0 < y1){
            cout << abs(x1 - x2) << endl;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}