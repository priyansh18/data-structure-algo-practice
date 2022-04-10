//  Stock Span Problem.

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
   public:
    stack<pair<int, int>> st;
    StockSpanner() {}

    int next(int price) {
        int res = 1;
        while (!st.empty() and st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }

        st.push({price, res});
        return res;
    }
};

int main() {
    StockSpanner stockSpanner;
    cout << stockSpanner.next(100) << endl;
    cout << stockSpanner.next(80) << endl;
    cout << stockSpanner.next(60) << endl;
    cout << stockSpanner.next(70) << endl;
    cout << stockSpanner.next(60) << endl;
    cout << stockSpanner.next(75) << endl;
    cout << stockSpanner.next(85) << endl;
}