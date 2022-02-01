#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define M 3
#define N 4

class Node {
   public:
    char ch;
    unordered_map<char, Node*> children;
    string word;
    bool isTerminal;

    Node(char s) {
        this->ch = s;
        this->isTerminal = false;
        word = "";
    }
};

class Trie {
   public:
    Node* root;

    Trie() { root = new Node('\0'); }

    void addWord(string word) {
        Node* temp = root;
        for (auto ch : word) {
            if (temp->children.count(ch) == 0) {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

void dfs(char board[M][N], Node* root, int i, int j, bool visited[][N],
         unordered_set<string>& output) {
    char ch = board[i][j];
    if (root->children.count(ch) == 0) {
        return;
    }

    visited[i][j] = true;
    root = root->children[ch];

    if (root->isTerminal) {
        output.insert(root->word);
    }
    // Explore the neighbours
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int k = 0; k < 8; k++) {
        int newI = i + dx[k];
        int newJ = j + dy[k];

        if (newI >= 0 and newJ >= 0 and newI < M and newJ < N and
            !visited[newI][newJ]) {
            dfs(board, root, newI, newJ, visited, output);
        }
    }

    visited[i][j] = false;

    return;
}

int main() {
    vector<string> words = {"SNAKE",  "FOR", "QUEZ",  "SNACK",
                            "SNACKS", "GO",  "TUNES", "CAT"};
    char board[M][N] = {
        {'S', 'E', 'R', 'T'}, {'U', 'N', 'K', 'S'}, {'T', 'C', 'A', 'T'}};

    // 1. Trie
    Trie t;
    for (auto word : words) {
        t.addWord(word);
    }

    // 2. Take a container to store words found in dfs search
    unordered_set<string> output;

    // 3. Step(8-DFS search from every cell)
    bool visited[M][N] = {0};

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dfs(board, t.root, i, j, visited, output);
        }
    }

    // Print the Output

    for (auto s : output) {
        cout << s << ",";
    }
}