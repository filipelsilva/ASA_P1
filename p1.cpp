#include <cstdio>
#include <vector>
#include <stack>

/* Usando iostream, teriam que ser colocadas:
 * ios_base::sync_with_stdio(false);
 * cin.tie(NULL);
 */

using namespace std;

enum colors { WHITE, GREY, BLACK };

class Node {
public:
	int id;
	int dist = 0;
	colors color = WHITE;
	vector<Node*> in = vector<Node*>();
	vector<Node*> out = vector<Node*>();

	Node(int id) {
		this->id = id;
	}
};

vector<Node*> dag;
vector<Node*> topological;
vector<Node*> sources;

void cleanGraph() {
	for (Node* n : dag)
		delete n;
}

int max_dist(Node* n) {
	int max = 0;

	for (Node* parent : n->in)
		if (parent->dist > max)
			max = parent->dist;

	return max;
}

int getMaxSequence() {
	int seq = -1;

	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		Node* n = *i;
		n->dist = max_dist(n) + 1;
		if (n->dist > seq)
			seq = n->dist;
	}

	return seq;
}

void DFS_Visit(Node* n) {
	stack<Node*> toVisit;
	toVisit.push(n);

	while (!toVisit.empty()) {
		Node* node = toVisit.top();
		node->color = GREY;

		for (Node* next : node->out)
			if (next->color == WHITE)
				toVisit.push(next);

		if (toVisit.top() == node) {
			node->color = BLACK;
			topological.push_back(node);
			toVisit.pop();
		}
	}
}

void findSources() {
	for (Node* n : dag)
		if (n->in.empty())
			sources.push_back(n);
}

void parseDAG() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		dag.push_back(new Node(i));

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dag[x-1]->out.push_back(dag[y-1]);
		dag[y-1]->in.push_back(dag[x-1]);
	}
}

int main(int argc, char *argv[]) {
	int times = -1;
	int seq = -1;

	parseDAG();
	findSources();
	times = sources.size();

	for (Node* n : sources)
		DFS_Visit(n);

	seq = getMaxSequence();
	printf("%d %d\n", times, seq);

	cleanGraph();
	return 0;
}
