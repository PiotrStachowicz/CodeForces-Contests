//Piotr Stachowicz
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<int> inp{};
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        inp.push_back(a);
    }
    std::sort(inp.begin(), inp.end());
    int h;
    int i = 0;
    for(int elem : inp){
        if(elem < 0) h = elem;
        else{
            while(i*i < elem){
                i++;
            }
            if(i*i != elem) h = elem;
        }
    }
    cout << h;
    return 0;
}