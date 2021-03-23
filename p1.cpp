#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> graph_trans;

void readGraph() {
	int n, m;
	scanf("%d,%d", &n, &m);
	// Alocar o espaco para o grafo
	graph = vector<vector<int>>(n, vector<int>());
	graph_trans = vector<vector<int>>(n, vector<int>());
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x-1].push_back(y-1);
		graph_trans[y-1].push_back(x-1);
	}
}

int main(int argc, char *argv[]) {
	return 0;
}
