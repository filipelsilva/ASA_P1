#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> dag;
vector<vector<int>> dag_trans;

void parseDAG() {
	int n, m;
	scanf("%d %d", &n, &m);
	dag = vector<vector<int>>(n, vector<int>());
	dag_trans = vector<vector<int>>(n, vector<int>());
	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dag[x-1].push_back(y-1);
		dag_trans[y-1].push_back(x-1);
	}
}

void topologicalSort() {}

void dfsoubfsnaosabemos() {}

int main(int argc, char *argv[]) {
	return 0;
}
