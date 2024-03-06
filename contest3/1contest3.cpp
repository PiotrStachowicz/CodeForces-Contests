//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    string vika{"vika"};
    vector<string> output;
    for(int j = 0; j < t; j++){
        cin >> n >> m;
        vector<string> rows;
        for(int i = 0; i < n ; i++){
            string row;
            cin >> row;
            rows.push_back(row);
        }
        vector<string> columns(m);
        for(auto row : rows){
            for(int i = 0; i < m; i++){
                columns[i] += row[i];
            }
        }
        int idx = 0, cp = 0;
        for(const auto& col: columns){
            for(char c : col){
                if(c == vika[idx]){
                    idx++;
                    if(idx == vika.size()){
                        cout << "YES" << endl;
                        cp = 1;
                    }
                    break;
                }
            }
        }
        if(cp != 1) cout << "NO" << endl;
    }

    return 0;
}