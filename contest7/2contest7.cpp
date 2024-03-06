//Piotr Stachowicz
#include <iostream>
#include <cmath>
using namespace std;
long long int n;

long long int binomial(int x, int k) {
    if(k == 0 || x == k) return 1;
    return binomial(x-1, k-1) + binomial(x-1, k);
}

int main() {
    cin >> n;
    long long int result = n*(n-1)*(n-2)*(n-3)*(n-4);
    cout << result*(binomial(n,5)) << endl;
    return 0;
}