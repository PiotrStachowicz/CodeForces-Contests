//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string string1;
    string string2;
    cin >> string1 >> string2;
    vector<int> frequency1(26, 0), frequency2(26, 0);
    for(char i : string1) frequency1[i - 'a']++;
    for(char i : string2) frequency2[i - 'a']++;
    // Need Tree
    for(int i = 0; i < frequency1.size(); i++){
        if(frequency2[i] > frequency1[i]){
            cout << "need tree";
            return 0;
        }
    }
    // Only Automaton
    int L = 0;
    int R = 0;
    while(L < string1.size() && R < string2.size()){
        if(string1[L] == string2[R]) R++;
        L++;
    }
    if(R == string2.size()){
        cout << "automaton";
        return 0;
    }
    // Only Array
    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());
    if(string1 == string2){
        cout << "array";
        return 0;
    }
    // Both
    cout << "both";
    return 0;
}