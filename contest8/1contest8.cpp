//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
string s;

long long int count(string& str){
    long long int res = 0;
    if(str[0] % 4 == 0) res++;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i+1] % 4 == 0) res ++;
        int l = str[i] - '0';
        int bl = str[i+1] - '0';
        int last = bl + 10*l;
        if(last % 4 == 0) res += i + 1;
    }
    return res;
}


int main() {
    cin >> s;
    cout << count(s);
    return 0;
}