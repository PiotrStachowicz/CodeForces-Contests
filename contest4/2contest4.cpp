//Piotr Stachowicz
#include <iostream>
#include <algorithm>
#include <vector>
long long l, m, n;
using hairline = std::vector<long long int>;

int answer(hairline h){
    int seconds;
    for(int i = 0; i < n; i++){
        if(h[i] > l && (i == 0 || (h[i - 1] <= l))) seconds++;
    }
    return seconds;
}

int main() {
    using namespace std;
    cin >> n >> m >> l;
    hairline hairline{};
    for(int i = 0; i < n; i++){
        long long int h;
        cin >> h;
        hairline.push_back(h);
    } // hairline input
    int seconds = answer(hairline);
    for(int i = 0 ; i < m; i++){
        int t;
        cin >> t;
        if(t == 0) cout << seconds << endl;
        else{
            long long p, d;
            cin >> p >> d;
            long long hair = hairline[p - 1];
            if(hair <= l && hair + d > l){ // now it's too much
                if(n == 1) seconds++;
                else if((p == 1 && hairline[p] <= l) || (p == n && hairline[p-2] <= l)) seconds++;
                else if((p != 1 && (hairline[p-2] > l) ) && (p != n && (hairline[p] > l))) seconds--;
                else if((p != 1 && (hairline[p-2] <= l) ) && (p != n && (hairline[p] <= l))) seconds++;
            }
            hairline[p - 1] += d;
        }
    } // requests
    return 0;
}