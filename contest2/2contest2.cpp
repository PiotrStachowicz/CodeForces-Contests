//Piotr Stachowicz
#include <iostream>
using namespace std;
int main() {
    long long int n, x, y, on = 0, off = 0;
    string bits{};
    cin >> n >> x >> y >> bits;
    for(int i = 0; i < n; i++){
        if(bits[i] == '0' && (i == 0 || bits[i-1] == '1')) off++;
        if(bits[i] == '1' && (i == 0 || bits[i-1] == '0')) on++;
    }
    if(off == 0){ cout << 0; return 0; }
    if(off > on) cout << (off+on-3)*min(x, y) + min(x+y, y+y);
    else cout << (off+on-3)*min(x, y) + x;
    return 0;
}