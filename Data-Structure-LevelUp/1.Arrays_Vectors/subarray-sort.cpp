#include <iostream>
#include <vector>
using namespace std;

void subarraySort(vector<int> a) {
    int n = a.size();
    int smallest = 0;
    int largest = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
            smallest = i;
        }
    }

    for (int j = n-2; j >= 1; j--) {
        if (a[j] < a[j + 1] and a[j] < a[j - 1]) {
            largest = j+1;
        }andand
    }

    cout << smallest << "," << largest;
}

int main() {
    vector<int> a{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    subarraySort(a);
}