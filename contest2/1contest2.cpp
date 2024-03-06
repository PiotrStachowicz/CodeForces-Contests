//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
int n;

vector<int> split(string current){
    int i{};
    vector<int> result;
    for(int idx = 0; idx < n; idx ++){
        if(current[idx] == '*'){
            if(i != 0)  result.push_back(i);
            i = 0;
        }else{
            i++;
        }
    }
    if(i > 0) result.push_back(i);
    return result;
}

int main() {
    int a, b{};
    string seats{};
    cin >> n; cin >> a; cin >> b;
    cin >> seats;
    vector<int> splits{split(seats)};
    int sum{};
    for(auto i : splits){
        if(a == 0 && b == 0) break;
        if(i % 2 == 0){
            int s = i/2;
            if(a >= s){
                a -= s;
                sum += s;
            }else{
                sum += a;
                a = 0;
            }
            if(b >= s){
                b -= s;
                sum += s;
            }else{
                sum += b;
                b = 0;
            }
        } else{
            if(a < b){
                int c = a;
                a = b;
                b = c;
            }
            int sa = i/2 + 1;
            int sb = i/2;
            if(a >= sa){
                a -= sa;
                sum += sa;
            }else{
                sum += a;
                a = 0;
            }
            if(b >= sb){
                b -= sb;
                sum += sb;
            }else{
                sum += b;
                b = 0;
            }
        }
    }
    cout << sum;
    return 0;
}