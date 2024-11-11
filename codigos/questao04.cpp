#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

class Graph {
private:
    vector<int> vis;
    vector<vector<int>> adj;
    vector<int> ages;
    vector<int> pos;

public:
    Graph() {}

    vector<vector<int>>& getAdj() {
        return adj;
    }

    vector<int>& getAges() {
        return ages;
    }

    vector<int>& getPos() {
        return pos;
    }

    vector<int>& getListAdj(int index) {
        return this->adj[index];
    }

    void initializeVis(int N) {
        setVis(N);
    }

    void setAges(int N) {
        ages.assign(N, 0);
    }

    void setVis(int N) {
        vis.assign(N, 0);
    }

    void setPos(int N) {
        pos.assign(N, 0);
    }

    void setAdj(int M) {
        adj.assign(500, vector<int>());
    }

    int depthFirstSearch(int ini, int lowest) {
        vis[ini] = 1;
        for (int v : adj[ini]) {
            if (vis[v] == 0) {
                if (ages[v] < lowest)
                    lowest = ages[v];
                lowest = depthFirstSearch(v, lowest);
            }
        }
        return lowest;
    }
};

void initializeGraphData(int N, int M, Graph& graph) {
    graph.setAges(N);
    graph.setAdj(M);
    graph.setVis(N);
    graph.setPos(N);
}

void readAjacentList(istream& in, int M, Graph& graph) {
    for (int i = 0; i < M; i++) {
        string line;
        getline(in, line);
        istringstream iss(line);
        int from, to;
        iss >> from >> to;
        graph.getListAdj(to - 1).push_back(from - 1);
    }
}

void readAges(istream& in, int N, Graph& graph) {
    string line;
    getline(in, line);
    istringstream iss(line);
    for (int i = 0; i < N; i++) {
        int age;
        iss >> age;
        graph.getAges()[i] = age;
        graph.getPos()[i] = i;
    }
}

void swapPlaces(Graph& graph, const string& line) {
    istringstream iss(line);
    string command;
    int vertexOne, vertexTwo;
    iss >> command >> vertexOne >> vertexTwo;

    swap(graph.getAges()[graph.getPos()[vertexOne - 1]], graph.getAges()[graph.getPos()[vertexTwo - 1]]);
    swap(graph.getPos()[vertexOne - 1], graph.getPos()[vertexTwo - 1]);
}

void analyseLowestAge(int N, Graph& graph, const string& line) {
    istringstream iss(line);
    string command;
    int vertex;
    iss >> command >> vertex;

    if (graph.getAdj()[graph.getPos()[vertex - 1]].empty()) {
        cout << "*\n";
    } else {
        graph.initializeVis(N);
        int lowest = numeric_limits<int>::max();
        lowest = graph.depthFirstSearch(graph.getPos()[vertex - 1], lowest);
        cout << lowest << "\n";
    }
}

void operations(istream& in, int N, int I, Graph& graph) {
    for (int i = 0; i < I; i++) {
        string line;
        getline(in, line);
        if (line[0] == 'P') {
            analyseLowestAge(N, graph, line);
        } else {
            swapPlaces(graph, line);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, I;
    Graph graph;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> N >> M >> I;

        initializeGraphData(N, M, graph);
        readAges(cin, N, graph);
        readAjacentList(cin, M, graph);
        operations(cin, N, I, graph);
    }

    return 0;
}