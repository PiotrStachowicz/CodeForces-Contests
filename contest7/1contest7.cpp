//Piotr Stachowicz
#include <iostream>
#include <cmath>
using namespace std;
int q;

bool contains(const string& str, const char& c){
    for(auto cc : str){
        if(cc == c) return true;
    }
    return false;
}

int main() {
    cin >> q;
    for(int i = 0; i < q; i++){
        string s, t;
        cin >> s >> t;
        if(contains(t,'a')){
            if(t.length() == 1) cout << 1 << endl;
            else cout << "-1" << endl;
        }else{
            cout << pow(2, s.length()) << endl;
        }
    }
    return 0;
}