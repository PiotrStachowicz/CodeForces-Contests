//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    map<int, int> degrees{};
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        degrees[v]++;
        degrees[u]++;
    }
    int one = 0;
    int two = 0;
    int more = 0;
    for(auto pair : degrees){
        if(pair.second == 1) one++;
        if(pair.second == 2) two++;
        if(pair.second == n-1) more++;
    }
    if(one == 2 && two == n-2) cout << "bus topology";
    else if(two == n) cout << "ring topology";
    else if(more == 1 && two == 0 && one == n-1) cout << "star topology";
    else cout << "unknown topology";
    return 0;
}
