//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
int t;

int main() {
    cin >> t;
    for(int i = 0; i < t; i++){
        int ti;
        cin >> ti;
        int first_idx = -1;
        bool c = true;
        for(int j = 0; j < ti; j++){
            long long int pile;
            cin >> pile;
            if(pile > 1 && c){
                first_idx = j;
                c = false;
            }
        }
        if(first_idx != -1){
            cout << (first_idx % 2 == 0 ? "First" : "Second") << endl;
        }else{
            ti % 2 != 0 ? cout << "First" << endl : cout << "Second" << endl;
        }
    }
    return 0;
}