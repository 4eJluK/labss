#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Graph represented as an adjacency list
unordered_map<string, vector<string>> graph = {
    {"A", {"S"}},
    {"B", {"C", "S"}},
    {"C", {"B", "J"}},
    {"D", {"S", "G"}},
    {"E", {"S", "G"}},
    {"F", {"H", "G"}},
    {"G", {"E", "D", "F", "H", "J"}},
    {"H", {"F", "G", "I"}},
    {"J", {"I", "G", "C"}},
    {"I", {"H", "J"}},
    {"S", {"A", "E", "D", "B"}}
};

// Breadth-First Search function
vector<string> bfs(unordered_map<string, vector<string>> graph, string start, string end) {
    queue<vector<string>> q;
    q.push({ start });

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();
        string node = path.back();

        if (node == end) {
            return path;
        }

        for (const string& adjacent : graph[node]) {
            vector<string> new_path(path);
            new_path.push_back(adjacent);
            q.push(new_path);
        }
    }

    return {}; // Return empty vector if no path is found
}

int main() {
    vector<string> path = bfs(graph, "S", "I");

    if (!path.empty()) {
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << "->";
            }
        }
        cout << endl;
    }
    else {
        cout << "No path found" << endl;
    }

    return 0;
}