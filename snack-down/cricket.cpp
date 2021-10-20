#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int countIndia = 0;
        int countEngland = 0;
        int countDraw = 0;
        if (a == 0) {
            countDraw++;
        } else if (a == 1) {
            countIndia++;
        } else {
            countEngland++;
        }

        if (b == 0) {
            countDraw++;
        } else if (b == 1) {
            countIndia++;
        } else {
            countEngland++;
        }

        if (c == 0) {
            countDraw++;
        } else if (c == 1) {
            countIndia++;
        } else {
            countEngland++;
        }

        if (d == 0) {
            countDraw++;
        } else if (d == 1) {
            countIndia++;
        } else {
            countEngland++;
        }

        if (e == 0) {
            countDraw++;
        } else if (e == 1) {
            countIndia++;
        } else {
            countEngland++;
        }

        if (countIndia > countEngland) {
            cout << "INDIA" << endl;
        } else if (countEngland > countIndia) {
            cout << "ENGLAND" << endl;

        } else {
            cout << "DRAW" << endl;
        }
    }
}