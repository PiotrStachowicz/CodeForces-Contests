//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, q;
int main() {
    cin >> n >> q;
    vector<long long> array{};
    for(int i = 0; i < n; i++){
        long long elem;
        cin >> elem;
        array.push_back(elem);
    }
    sort(array.begin(), array.end());
    vector<long long> map(n+1, 0);
    for(int i = 0; i < q; i++){
        long long l, r;
        cin >> l >> r;
        map[l-1]++;
        map[r]--;
    }
    for(int i = 1; i <= n; i++){
        map[i] += map[i-1];
    }
    sort(map.begin(), map.end());
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += map[i]*array[i-1];
    }
    cout << sum;
    return 0;
}