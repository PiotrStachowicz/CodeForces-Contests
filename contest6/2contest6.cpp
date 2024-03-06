//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;

vector<bool> SIEVE(long long int MAX = 1e6){
    vector<bool> sieve(MAX+1,true);
    sieve[0] = false; sieve[1] = false;
    for(long long int i = 2; i*i <= MAX; i++){
        if(sieve[i]){
            for(int j = i*i; j <= MAX; j+= i){
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

int main() {
    cin >> n;
    vector<bool> sieved = SIEVE();
    for(int i = 0; i < n; i++){
        long long int xi;
        cin >> xi;
        long double sqr = sqrtl(xi);
        // must be y*y = a and y isn't devisible
        if(sqr == (long long int)sqr && sieved[sqr]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}