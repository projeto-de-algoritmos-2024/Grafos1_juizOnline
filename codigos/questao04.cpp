#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

bool isStronglyConnected(int n, vector<vector<int>>& adj, vector<vector<int>>& adjT) {
    vector<bool> visited(n + 1, false);

    // Realiza DFS a partir do nó 1 no grafo original
    dfs(1, adj, visited);

    // Verifica se todos os nós foram visitados
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) return false;
    }

    // Reinicia o vetor de visitados para o grafo transposto
    fill(visited.begin(), visited.end(), false);

    // Realiza DFS a partir do nó 1 no grafo transposto
    dfs(1, adjT, visited);

    // Verifica se todos os nós foram visitados no grafo transposto
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adjT(n + 1);

    // Lê as arestas e constrói o grafo e o grafo transposto
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    // Grafo original
        adjT[v].push_back(u);    // Grafo transposto
    }

    // Verifica se o grafo é fortemente conexo
    if (isStronglyConnected(n, adj, adjT)) {
        cout << "Bolada" << endl;
    } else {
        cout << "Nao Bolada" << endl;
    }

    return 0;
}