//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        string ans;
        cin >> ans;
        int size = ans.size();
        bool war1 = false, war2 = false;
        int war3{};
        bool il0 = false;
        for(int j = 0; j < size; j++){
            if(ans[j] != '0'){
                if(!war1 && (ans[j]) % 2 == 0) war1 = true;
                war3 += ans[j];
            }
            else{
                if(il0) war1 = true;
                war2 = true;
                il0 = true;
            }
        }
        if(war1 && war2 && (war3 % 3 == 0)) cout << "red" << endl;
        else cout << "cyan" << endl;
    }
    return 0;
}