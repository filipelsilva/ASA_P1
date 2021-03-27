#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void readGraph() {
	int n, m;
	scanf("%d %d", &n, &m);
	graph = vector<vector<int>>(n, vector<int>());
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x-1].push_back(y-1);
	}
}

void topologicalSort() {}

void dfsoubfsnaosabemos() {}

int main(int argc, char *argv[]) {
	return 0;
}
