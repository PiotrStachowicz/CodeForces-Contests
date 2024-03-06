//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
int t;

// a - tylko anna
// b - tylko cait
// c - oboje


int main() {
    cin >> t;
    for(int i = 0; i < t; i++){
        long long int a,b,c;
        cin >> a >> b >> c;
        if(a > b){
            cout << "First" << endl;
        }else if(a == b){
            if(c % 2 == 1){
                cout << "First" << endl;
            }else{
                cout << "Second" << endl;
            }
        }else{
            cout << "Second" << endl;
        }
    }
    return 0;
}