//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
int kc; // number of colors ( 1 <= k <= 1000)

vector<vector<long long int>> memo(1001, vector<long long int>(1001, -1));

long long int binomial(int x, int k) {
    if(k == 0 || x == k) return 1;
    if(memo[x][k] != -1){
        return memo[x][k];
    }
    memo[x][k] = ( (binomial(x-1, k-1) % 1000000007) + (binomial(x-1, k) % 1000000007) ) % 1000000007;
    return memo[x][k];
}

long long int ways(vector<int>& types){
    long long int res{1};
    for(int i = 1; i < kc; i++){
        int type{};
        for(int j = 0; j <= i; j++){
            type += types[j];
        }
        res = ( (res % 1000000007) * (binomial(type-1, types[i] - 1) % 1000000007) ) % 1000000007;
    }
    return res % 1000000007;
}

int main() {
    vector<int> ci{};
    cin >> kc;
    for(int i = 0; i < kc; i++){
        int c;
        cin >> c;
        ci.push_back(c);
    } // input
    cout << ways(ci) << endl;

    return 0;
}