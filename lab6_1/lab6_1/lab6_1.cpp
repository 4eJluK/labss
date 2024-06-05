#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int dijkstra(int N, int S, int F, const vector<vector<int>>& adj) {
    vector<int> dist(N, INF);
    dist[S] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, S);

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < N; ++v) {
            if (adj[u][v] != -1 && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist[F] == INF ? -1 : dist[F];
}

int main() {
    int N = 5;
    int S = 1; // начальная вершина
    int F = 5; // конечная вершина
    --S; --F; // переводим вершины в 0-индексацию

    vector<vector<int>> adj = {
        {0, 10, -1, 30, 100},
        {10, 0, 50, -1, -1},
        {-1, 50, 0, 20, 10},
        {30, -1, 20, 0, 60},
        {100, -1, 10, 60, 0}
    };

    int result = dijkstra(N, S, F, adj);
    cout << result << endl;

    return 0;
}
