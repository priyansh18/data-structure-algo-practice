#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int ropes[] = {4, 2, 3, 6 };
    int n = 4;

    priority_queue<int, vector<int>, greater<int>> q(ropes, ropes + n);

    int cost = 0;

    while (q.size() > 1) {
        int c1 = q.top();
        q.pop();
        int c2 = q.top();
        q.pop();

        cost += (c1 + c2);
        q.push(c1 + c2);
    }

    cout << "Minimum Cost of Merging two ropes is : " << cost << endl;
}