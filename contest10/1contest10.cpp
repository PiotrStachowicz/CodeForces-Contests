//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;
int t;
void check(const string& current, int n) {
    string result{};
    result.push_back(current[0]);
    char last = current[0];
    if(current[0] == current[1]){
        string ans = string(1, current[0]) + string(1, current[1]);
        cout << ans << endl;
        return;
    }
    for (int i = 1; i < n; ++i) {
        char c = current[i];
        if (c > last)
            break;
        else {
            last = c;
            result.push_back(c);
        }
    }

    string reverse(result.rbegin(), result.rend());
    cout << result + reverse << endl;
}

int main() {
    cin >> t;
    int n;
    string str;
    while(t--){
        cin >> n;
        cin >> str;
        check(str, n);
    }
    return 0;
}