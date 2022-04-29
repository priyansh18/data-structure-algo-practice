// Reorganize String.

#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, char>

class Solution {
   public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        priority_queue<Pair, vector<Pair>> maxHeap;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        for (auto x : m) {
            maxHeap.push({x.second, x.first});
        }

        string result = "";
        while (maxHeap.size() > 1) {
            char current = maxHeap.top().second;
            maxHeap.pop();
            char next = maxHeap.top().second;
            maxHeap.pop();
            result += current;
            result += next;
            m[current]--;
            m[next]--;
            if (m[current] > 0) maxHeap.push({m[current], current});
            if (m[next] > 0) maxHeap.push({m[next], next});
        }

        if(maxHeap.empty()){
            return result;
        }else{
            char d = maxHeap.top().second;
            if (m[d] > 1) {
                return "";
            } else {
                result += d;
            }
        }


        return result;
    }
};

int main() {
    Solution a;
    string s = "aaba";
    cout << a.reorganizeString(s) << endl;
}