//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<long long int>> memo(1001, vector<long long int>(1001, -1));

long long int binomial(int x, int k) {
    if(k == 0 || x == k) return 1;
    if(memo[x][k] != -1){
        return memo[x][k];
    }
    memo[x][k] = binomial(x-1, k-1) + binomial(x-1, k);
    return memo[x][k];
}

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int pos1 = 0;
    int pos2 = 0;
    int qmark = 0;
    for(auto c : s1){
        if(c == '+') pos1++;
        else pos1--;
    }
    for(auto c : s2){
        if(c == '+') pos2++;
        else if(c == '-') pos2--;
        else qmark++;
    }
    int odl = abs(pos1 - pos2);
    if(odl > qmark || odl % 2 != qmark % 2) cout << 0.0;
    else{
        double ways = 1 << qmark;
        int p = (odl + qmark)/2;
        cout << fixed << setprecision(20) << ((double)binomial(qmark, p))/ways;
    }
    return 0;
}