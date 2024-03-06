//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k{};
long long int S, T{0};
vector<int> costs{};

vector<long long int> update_cost_sorted(int newK){
    vector<long long int> newCost{};
    for(int i = 0; i < n; i++){
        newCost.push_back(costs[i] + (long long int)(i+1)*newK);
    }
    sort(newCost.begin(), newCost.end());
    return newCost;
}

void binsearch(){
    int left = 1;
    int right = n;
    while(left <= right){
        int mid = left + (right - left)/2;
        vector<long long int> sorted_costs = update_cost_sorted(mid);
        long long sum = 0;
        for(int i = 0; i < mid; i++){
            sum += sorted_costs[i];
        }
        if(sum > S){
            right = mid - 1;
        }else{
            T = sum;
            k = mid;
            left = mid + 1;
        }
    }
}

int main() {
    cin >> n >> S;
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        costs.push_back(ai);
    }
    binsearch();
    cout << k << " " << T;
    return 0;
}