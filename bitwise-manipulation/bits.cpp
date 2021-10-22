#include <iostream>
using namespace std;

// Get Bit from a particular location
int getBit(int n, int pos) {
    if ((n & (1 << pos)) != 0) {
        return 1;
    } else {
        return 0;
    }
}
// Set Bit at particular location
int setBit(int n, int pos) { return (n | (1 << pos)); }

// Clear Bit
int clearBit(int n, int pos) { return (n & ~(1 << pos)); }

int updateBit(int n,int pos){
    n = clearBit(n,pos);
    int ans = setBit(n,pos);
    return ans;

}

int main() {
    int n;
    cin >> n;
    cout << getBit(n, 2) << endl;
    int ans = setBit(n, 2);
    cout << ans << endl;
    cout << clearBit(n, 1) << endl;
    cout<<updateBit(n,1);
}
