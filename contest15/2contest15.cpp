//Piotr Stachowicz
#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>
using namespace std;
long long int ax, bx, cx, ay, by, cy;

long long int length(long long int x, long long int y){
    return x*x + y*y;
}

int main() {
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // vector from a to b
    long long int abx = bx - ax;
    long long int aby = by - ay;
    // vector from b to c
    long long int bcx = cx - bx;
    long long int bcy = cy - by;

    long double lengthab = length(abx, aby);
    long double lengthbc = length(bcx, bcy);

    long double slope1 = static_cast<long double>(by - ay)/(bx - ax);
    long double slope2 = static_cast<long double>(cy - by)/(cx - bx);

    if(lengthab == lengthbc && slope1 != slope2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}