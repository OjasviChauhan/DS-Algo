#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b){
    
    return a*b/gcd(a,b);
}

int x,y,GCD;

void extendedEuclidMethod(int a, int b){
    // base case
    if(b == 0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    
    // recursive case
    extendedEuclidMethod(b, a % b);
    int Cx = y;
    int Cy = x - (a/b) * y;
    
    x = Cx;
    y = Cy;
}

int main() {
    
    cout << gcd(18,30) << endl;
    cout << lcm(18,30) << endl;
    
    extendedEuclidMethod(18, 30);
    cout << x << "," << y << endl;
    
}
