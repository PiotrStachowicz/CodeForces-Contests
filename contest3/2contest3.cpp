// Piotr Stachowicz
#include <iostream>
#include <algorithm>
int m,n,a,b,c;
using namespace std;
int main() {
    cin >> n >> a >> b >> c;
    for(int xA = 0; xA <= n; xA += a){
        for(int xB = 0; xB <= n - xA; xB += b){
            int difference{n - xA - xB};
            if(difference == 0){ m = max(m, xA/a + xB/b); }
            else { if(difference % c == 0) { m = max(m, xA/a + xB/b + difference/c); } }
        }
    }
    cout << m;
    return 0;
}