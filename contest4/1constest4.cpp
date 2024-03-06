//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using permutations = std::vector<int>;
int q, n;

std::ostream& operator<<(std::ostream& o, const permutations& p){
    for(auto ans: p){
        o << ans << " ";
    }
    o << std::endl;
    return o;
}
permutations answer(const permutations& perms){
    permutations result{};
    for(int kid = 0; kid < n; kid++){
        int current = kid, day = 0;
        while(true){
            current = perms[current]-1;
            day++;
            if(current == kid) { result.push_back(day); break; }
        }
    }
    return result;
}

int main() {
    using namespace std;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> n;
        permutations perms{};
        for(int j = 0; j < n; j++){
            int p;
            cin >> p;
            perms.push_back(p);
        } // perms
        cout << answer(perms);
    } // query
    return 0;
}