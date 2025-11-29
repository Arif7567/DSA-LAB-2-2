#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;            // to node
    long long cap;    // remaining capacity
    int rev;          // index of reverse edge
};

class Dinic {
public:
    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    Dinic(int n) {
        this->n = n;
        adj.assign(n, {});
        level.resize(n);
        ptr.resize(n);
    }

    void addEdge(int u, int v, long long cap) {
        Edge a = {v, cap, (int)adj[v].size()};
        Edge b = {u, 0, (int)adj[u].size()}; // reverse (0 capacity)
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(const auto &e : adj[u]) {
                if (e.cap > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, long long pushed, int t) {
        if (u == t || pushed == 0) return pushed;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            Edge &e = adj[u][cid];
            if (e.cap > 0 && level[e.v] == level[u] + 1) {
                long long tr = dfs(e.v, min(pushed, e.cap), t);
                if (tr == 0) continue;

                e.cap -= tr;
                adj[e.v][e.rev].cap += tr;
                return tr;
            }
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, LLONG_MAX, t))
                flow += pushed;
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Dinic mf(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        mf.addEdge(u, v, w);
    }

    int source, sink;
    cin >> source >> sink;

    cout << "Maximum Flow: " << mf.maxFlow(source, sink) << "\n";
    return 0;
}
