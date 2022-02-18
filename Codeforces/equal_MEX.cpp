#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool CanMEXbeEqual(vector<int> arr) {
    unordered_map<int, int> m;
    for (auto x : arr) {
        m[x]++;
    }

    if (m.count(0) == 0) {
        return true;
    }

    int i = 0;

    while (true) {
        if (m.count(i) != 0 and m[i] < 2) {
            return false;
        }else if(m.count(i)==0){
            return true;
        }else{
            i++;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr;
        int y = 2 * N;
        while (y--) {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        CanMEXbeEqual(arr) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}