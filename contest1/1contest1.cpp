//Piotr Stachowicz
#include <iostream>
#include <vector>
using namespace std;

int addr(int i, int j, vector<int> board, int rows, int cols){
    int sum{};
    while(i >= 0 && j < cols){
        sum += board[cols*i + j];
        i--;
        j++;
    }
    return sum;
}

int addl(int i, int j, vector<int> board, int rows, int cols){
    int sum{};
    while(i < rows && j < cols){
        sum += board[cols*i + j];
        i++;
        j++;
    }
    return sum;
}

int main() {
    int t{}; // 1 <= t <= 1000 test cases
    cin >> t;
    for(int i = 0; i < t; i++){ // for test cases
        int n{};
        int m{};
        int max = INT_MIN;
        cin >> n;
        cin >> m;
        vector<int> board{};
        for(int j = 0; j < n*m; j++){
            int value{};
            cin >> value;
            board.push_back(value);
        }
        vector<int> diagR{}; // all "right" diagonals
        vector<int> diagL{}; // all "left" diagonals
        // calculate diagonals...
        for(int row = 0; row < n; row++){
            diagR.push_back(addr(row, 0, board, n, m));
        }
        for(int column = 1; column < m; column++){
            diagR.push_back(addr(n - 1, column, board, n, m));
        }
        for(int column = m - 1; column >=0; column--){
            diagL.push_back(addl(0 , column, board, n , m));
        }
        for(int row = 1; row < n; row++){
            diagL.push_back(addl(row , 0, board, n , m));
        }
        // put bishop on all squares...
        for(int row = 0; row < n; row++){
            for(int cols = 0; cols < m; cols++){
                int s = diagR[row+cols] + diagL[m - cols + row - 1] - board[row*m + cols];
                if(s > max){
                    max = s;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}