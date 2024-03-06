//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool in(const vector<int>& cube, int i) {
    return find(cube.begin(), cube.end(), i) != cube.end();
}

vector<int> whichCubes(const vector<vector<int>>& cubes, int i) {
    vector<int> result;
    for (int iter = 0; iter < cubes.size(); iter++) {
        if (in(cubes[iter], i)) {
            result.push_back(iter);
        }
    }
    return result;
}

int main(){
    int n{}; cin >> n;
    vector<vector<int>> cubes{};
    for(int i = 0; i < n; i++){
        vector<int> cube{};
        for(int j = 0; j < 6; j++){
            int h;
            cin >> h;
            cube.push_back(h);
        }
        cubes.push_back(cube);
    } // input
    int max{0};
    for(int i = 1; i <= 99; i++){
        if(i < 10){
            if(!whichCubes(cubes, i).empty()) max = i;
            else{ cout << max; return 0; }
        } else {
            int first = i / 10;
            int second = i % 10;
            vector<int> fstI = whichCubes(cubes, first);
            vector<int> sndI = whichCubes(cubes, second);
            if(sndI.empty() || fstI.empty()){ cout << max; return 0; }
            if(sndI.size() == fstI.size() && sndI.size() == 1 && in(fstI, sndI[0])){
                cout << max;
                return 0;
            }
            max = i;
        }
    }
    cout << max;
    return 0;
}