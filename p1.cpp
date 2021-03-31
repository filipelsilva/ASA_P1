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
	int close = 0;
	/* set<Node*> in; */
	/* set<Node*> out; */
	vector<Node*> in = vector<Node*>();
	vector<Node*> out = vector<Node*>();
	Node(int id) {
		this->id = id;
	}
};

int timer = 0;
vector<Node*> dag;
vector<Node*> topological;

int DFS_Visit(Node* n) {
	assert(n->color == WHITE);
	n->color = GREY;
	timer++;
	for (Node* next : n->out) {
		if (next->color == WHITE) {
			timer = DFS_Visit(next);
		}
	}
	n->color = BLACK;
	timer++;
	n->close = timer;
	topological.push_back(n);
	return timer;
}

void DFS() {
	for (Node* n : dag) {
		n->color = WHITE;
	}
	int time = 0;
	for (Node* n : dag) {
		if (n->color == White) {
			time = DFS_Visit(n);
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
		dag[x-1]->out.push_back(dag[y-1]);
		dag[y-1]->in.push_back(dag[x-1]);
	}
}

void cleanProgram() {
	for (Node* n : dag) {
		delete n;
	}
}

int max_dist(Node* n) {
	int max = 0;
	for (Node* parent : n->in) {
		if (parent->dist > max) {
			max = parent->dist;
		}
	}
	return max;
}

int main(int argc, char *argv[]) {
	parseDAG();
	vector<Node*> sources = findSources();
	for (Node* n : sources) {
		DFS_Visit(n);
	}
	int max = 0;
	for (auto i = topological.rbegin(); i != topological.rend(); i++) {
		Node* n = *i;
		/* cout << "Node " << n->id + 1 << endl; */
		n->dist = max_dist(n) + 1;
		/* cout << n->dist << endl; */
		if (n->dist > max) {
			max = n->dist;
		}
	}
	cout << sources.size() << " " << max << endl;
	/* for (Node* n : dag) { */
	/* 	cout << "Node " << n->id + 1 << endl; */
	/* 	for (Node* nn : n->out) { */
	/* 		cout << nn->id + 1 << endl; */
	/* 	} */
	/* } */
	cleanProgram();
	return 0;
}
