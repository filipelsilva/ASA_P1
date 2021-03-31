#include <iostream>
#include <vector>
#include <stack>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Node {
public:
	int id;
	int dist = 0;
	int color = WHITE;
	vector<Node*> in = vector<Node*>();
	vector<Node*> out = vector<Node*>();

	Node(int id) {
		this->id = id;
	}
};

int timer = 0;
vector<Node*> dag;
vector<Node*> topological;
vector<Node*> sources;

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

//int DFS_Visit(Node* n) {
//	assert(n->color == WHITE);
//	n->color = GREY;
//	timer++;
//	n->dist = timer;
//	for (Node* next : n->out) {
//		if (next->color == WHITE) {
//			next->father = n;
//			timer = DFS_Visit(next);
//		}
//	}
//	n->color = BLACK;
//	timer++;
//	n->close = timer;
//	return timer;
//}

void DFS() {
	for (Node* n : dag)
		n->color = WHITE;

	timer = 0;
	for (Node* n : dag)
		if (n->color == WHITE)
			DFS_Visit(n);
}

int countSources() {
	int ret = 0;
	for (Node* n : dag)
		if (n->in.empty())
			ret++;

	return ret;
}

void parseDAG() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		dag.push_back(new Node(i));

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dag[x-1]->out.push_back(dag[y-1]);
		dag[y-1]->in.push_back(dag[x-1]);
	}
}

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

int main(int argc, char *argv[]) {
	int times = -1;
	int seq = -1;

	parseDAG();

	times = countSources();

	DFS();

	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		Node* n = *i;
		n->dist = max_dist(n) + 1;
		if (n->dist > seq) {
			seq = n->dist;
		}
	}

	/* for (Node* n : dag) { */
	/* 	cout << "Node " << n->id + 1 << endl; */
	/* 	cout << n->dist << endl; */
		/* for (Node* nn : n->out) { */
		/* 	cout << nn->id + 1 << endl; */
		/* } */
	/* } */

	cout << times << " " << seq << endl;
	cleanGraph();

	return 0;
}
