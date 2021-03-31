#include <iostream>
#include <vector>
#include <set>
#include <cassert>

#include <cstdio>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Node {
private:
    bool operator <(const Node& other) {
        return id < other.id;
    }

public:
	int id;
	int dist = 0;
	int color = WHITE;
	int close;
	Node* father = NULL;
	set<Node*> in;
	set<Node*> out;

	Node(int id) {
		this->id = id;
	}
};

int timer;
vector<Node*> dag;

int DFS_Visit(Node* n) {
	assert(n->color == WHITE);
	n->color = GREY;
	timer++;
	n->dist = timer;
	for (Node* next : n->out) {
		if (next->color == WHITE) {
			next->father = n;
			timer = DFS_Visit(next);
		}
	}
	n->color = BLACK;
	timer++;
	n->close = timer;
	return timer;
}

void DFS() {
	for (Node* n : dag) {
		n->color = WHITE;
		n->father = NULL;
	}
	timer = 0;
	for (Node* n : dag) {
		if (n->color == WHITE) {
			timer = DFS_Visit(n);
		}
	}
}

vector<Node*> findSources() {
	vector<Node*> ret = vector<Node*>();
	for (Node* n : dag) {
		if (n->in.empty()) {
			ret.push_back(n);
		}
	}
	return ret;
}

void parseDAG() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		Node* tmp = new Node(i);
		dag.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dag[x-1]->out.insert(dag[y-1]);
		dag[y-1]->in.insert(dag[x-1]);
	}
}

void cleanProgram() {
	for (Node* n : dag) {
		delete n;
	}
}

int main(int argc, char *argv[]) {
	parseDAG();
	vector<Node*> sources = findSources();
	DFS();

	for (Node* n : dag) {
		cout << "Node " << n->id + 1 << endl;
		for (Node* nn : n->out) {
			cout << nn->id + 1 << endl;
		}
		cout << "\tEnd timer: " << n->close << endl;
		cout << "\tColor: " << n->color << endl;
		if (n->father != NULL)
			cout << "\tFather: " << n->father->id + 1 << endl;
	}

	cleanProgram();
	return 0;
}
