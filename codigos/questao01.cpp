#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int MAX = 1e9;

        vector<vector<pair<int, int>>> grafo(n);
        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            grafo[from].push_back({to, price});
        }
     
        queue<vector<int>> filaBFS;
        filaBFS.push({src, 0, 0});
        
        vector<int> minCusto(n, MAX);
        minCusto[src] = 0;

        while (!filaBFS.empty()) {
            int cidade = filaBFS.front()[0];
            int custo = filaBFS.front()[1];
            int paradas = filaBFS.front()[2];
            filaBFS.pop();

            if (paradas > k) continue;

            for (int i = 0; i < grafo[cidade].size(); i++) {
                int vizinho = grafo[cidade][i].first;
                int preco = grafo[cidade][i].second;
                int novoCusto = custo + preco;

                if (novoCusto < minCusto[vizinho]) {
                    minCusto[vizinho] = novoCusto;
                    filaBFS.push({vizinho, novoCusto, paradas+1});
                }
            }
        }

        return (minCusto[dst] == MAX) ? -1 : minCusto[dst];
    }
};
