#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> resposta;
        set<string> visitado;
        queue<string> filaBFS;
        filaBFS.push(s);
        visitado.insert(s);
        bool ehValida = false;

        while (!filaBFS.empty()) {
            string atual = filaBFS.front();
            filaBFS.pop();

            if (valida(atual)) {
                resposta.push_back(atual);
                ehValida = true;
            }

            if (ehValida) continue;

            for (int i = 0; i < atual.size(); i++) {
                if (atual[i] != '(' && atual[i] != ')') continue;
                
                string novaString = atual.substr(0, i) + atual.substr(i + 1);
                
                if (visitado.find(novaString) == visitado.end()) {
                    filaBFS.push(novaString);
                    visitado.insert(novaString);
                }
            }
        }
        
        return resposta;
    }

    bool valida(string& s) {
        int contador = 0;
        for (char c : s) {
            if (c == '(') contador++;
            else if (c == ')') {
                if (contador == 0) return false;
                contador--;
            }
        }
        return contador == 0;
    }
};
