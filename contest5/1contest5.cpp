//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector<long long int> a{};

int binary_check(long long int bj) {
    int left = 0, right = n - 1;
    int result = n;
    while (left <= right) {
        int mid = left + (right - left)/2;
        long long int val = a[mid];
        if (val <= bj) left = mid + 1;
        else if(val > bj) {right = mid - 1; result = mid; }
    }
    return result;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long int aj{};
        cin >> aj;
        a.push_back(aj);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        long long int bj{};
        cin >> bj;
        cout << binary_check(bj) << " ";
    }
    return 0;
}