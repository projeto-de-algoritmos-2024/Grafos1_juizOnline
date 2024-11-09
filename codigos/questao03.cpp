#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int l;
        cin >> l;

        vector<vector<int>> grid(l + 1, vector<int>(l + 1, 0));

        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= l; ++j) {
                cin >> grid[i][j];
            }
        }

        queue<int> pontos;

        for (int j = 1; j <= l; ++j) {
            pontos.push(100 + j);
            pontos.push(100 * l + j);
            pontos.push(100 * j + 1);
            pontos.push(100 * j + l);
        }

        double area = (l * l) / 2.0;

        while (!pontos.empty()) {
            int ponto = pontos.front();
            pontos.pop();
            
            int x = ponto / 100;
            int y = ponto % 100;

            if (x > 0 && y > 0 && x <= l && y <= l && grid[x][y] == 0) {
                area -= 0.5;
                grid[x][y] = -1;

                pontos.push(ponto - 100);  
                pontos.push(ponto + 100);  
                pontos.push(ponto + 1);    
                pontos.push(ponto - 1);    
            }
        }

        printf("%.2f\n", area);
    }

    return 0;
}