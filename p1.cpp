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
	Node* father = NULL;
	vector<Node*> in = vector<Node*>();
	vector<Node*> out = vector<Node*>();

	Node(int id) {
		this->id = id;
	}

	void changeDist(int dist) {
		this->dist = dist;
	}

	void addFather(Node* n) {
		this->father = n;
	}

	void addIn(Node* n) {
		this->in.push_back(n);
	}

	void addOut(Node* n) {
		this->out.push_back(n);
	}
};

vector<Node> dag;

/* int DFS_Visit(Node n, time) { */

/* } */

/* void DFS() { */
/* 	int time = 0; */
/* 	for (Node n : dag) { */
/* 		if (n.color == WHITE) { */
/* 			time = DFS_Visit(n, time); */
/* 		} */
/* 	} */
/* } */

void parseDAG() {
	/* int n, m; */
	/* cin >> n >> m; */
	int n = 10;
	dag.reserve(n);
	for (int i = 0; i < n; i++) {
		dag.push_back(Node(i));
	}
	dag[4].addOut(&dag[3]);
	dag[4].addOut(&dag[8]);
	dag[4].addIn(&dag[5]);
	dag[4].addIn(&dag[7]);
	for (Node* n : dag[4].out) {
		printf("%d\n", n->id);
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
		for (Node* nn : n.in) {
			printf("%d\n", nn->id);
		}
	}
	return 0;
}
