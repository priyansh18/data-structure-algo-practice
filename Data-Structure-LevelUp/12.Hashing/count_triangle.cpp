#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count_triangles(vector<pair<int, int>> &points) {
    unordered_map<int, int> countX;
    unordered_map<int, int> countY;

    for (auto p : points) {
        int x = p.first;
        int y = p.second;

        countX[x]++;
        countY[y]++;
    }

    int count = 0;
    for (auto p : points) {
        int x = p.first; int y = p.second;

        int fx = countX[x];
        int fy = countX[y];

        count += (fx - 1) * (fy - 1);
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    cout << count_triangles(points) << endl;
}