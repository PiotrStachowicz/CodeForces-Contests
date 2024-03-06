//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
    cin >> n;
    vector<int> likes{};
    for(int i = 0; i < n; i++){
        int like;
        cin >> like;
        likes.push_back(like);
    }
    for(int i = 0; i < n; i++){
        int next = likes[i];
        int length = 1;
        while(next-1 != i && length < 3){
            length++;
            next = likes[next - 1];

        }
        if(next-1 == i && length == 3){
            cout << "YES";
            return 0;
        }
        cout << endl;
    }
    cout << "NO";
    return 0;
}