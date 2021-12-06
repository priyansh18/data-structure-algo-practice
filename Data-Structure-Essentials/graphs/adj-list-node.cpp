#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
class Node {
   public:
    string name;
    list<string> nbrs;
    Node(string n) { this->name = n; }
};

class Graph {
    unordered_map<string, Node *> m;

   public:
    Graph(vector<string> cities) {
        for (auto city : cities) {
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = false) {
        m[x]->nbrs.push_back(y);
        if (undir) {
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList() {
        for (auto cityPair : m) {
            Node *node = cityPair.second;
            cout << cityPair.first << " --->> ";
            for (auto nbr : node->nbrs) {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> cities = {"Delhi", "London", "Paris", "San Francisco",
                             "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "San Francisco");
    g.addEdge("Delhi", "Paris");
    g.addEdge("New York", "Paris");
    g.addEdge("London", "New York");
    g.addEdge("Paris", "San Francisco");
    g.addEdge("San Francisco","Paris");

    g.printAdjList();
}