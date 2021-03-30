#include <iostream>
#include <cstdio>
#include <vector>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Node {
public:
	int id;
	int dist = 0;
	int color = WHITE;
	/* Node* father = NULL; */
	/* vector<Node*> in = vector<Node*>(); */
	/* vector<Node*> out = vector<Node*>(); */

	Node(int id) {
		this->id = id;
	}

	void changeDist(int dist) {
		this->dist = dist;
	}

	/* void addFather(Node* n) { */
	/* 	this->father = n; */
	/* } */

	/* void addIn(Node* n) { */
	/* 	this->in.push_back(n); */
	/* } */

	/* void addOut(Node* n) { */
	/* 	this->out.push_back(n); */
	/* } */
};

vector<Node> dag;

/* void DFS() { */
/* 	for (int i = 0; i < dag.size(); i++) { */

/* 	} */
/* } */

void parseDAG() {
	int n, m;
	cin >> n >> m;
	dag.reserve(n);
	for (int i = 0; i < n; i++) {
		dag.push_back(Node(i));
	}
	/* for (int i = 0; i < m; i++) { */
	/* 	int x, y; */
	/* 	cin >> x >> y; */
	/* 	dag[x-1].addOut(&dag[y-1]); */
	/* 	dag[y-1].addIn(&dag[x-1]); */
	/* } */
}

void topologicalSort() {}

void dfsoubfsnaosabemos() {}

int main(int argc, char *argv[]) {
	parseDAG();
	for (Node n : dag) {
		printf("%d\n", n.color);
	}
	return 0;
}
