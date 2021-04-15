#include <cstdio>
#include <vector>
#include <stack>

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

	void setMaxDist();
};

class Graph {
public:
	int maxSequence = -1;
	int numSources = -1;

	vector<Node*> nodes = vector<Node*>();
	vector<Node*> topological = vector<Node*>();
	vector<Node*> sources = vector<Node*>();

	void getMaxSequence();
	void DFS_Visit(Node* n);
	void DFS_VisitSources();
	void findSources();
	void clean();
};

void Node::setMaxDist() {
	int max = 0;

	for (Node* parent : this->in)
		if (parent->dist > max)
			max = parent->dist;

	this->dist = max + 1;
}

void Graph::getMaxSequence() {
	for (auto i = this->topological.rbegin(); i != this->topological.rend(); i++) {
		Node* n = *i;
		n->setMaxDist();
		if (n->dist > this->maxSequence)
			this->maxSequence = n->dist;
	}
}

void Graph::DFS_Visit(Node* n) {
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
			this->topological.push_back(node);
			toVisit.pop();
		}
	}
}

void Graph::DFS_VisitSources() {
	for (Node* n : this->sources)
		DFS_Visit(n);
}

void Graph::findSources() {
	for (Node* n : this->nodes)
		if (n->in.empty())
			this->sources.push_back(n);

	this->numSources = this->sources.size();
}

void Graph::clean() {
	for (Node* n : this->nodes)
		delete n;
}

Graph parseDAG() {
	Graph ret;

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		ret.nodes.push_back(new Node(i));

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ret.nodes[x-1]->out.push_back(ret.nodes[y-1]);
		ret.nodes[y-1]->in.push_back(ret.nodes[x-1]);
	}

	return ret;
}

int main(int argc, char *argv[]) {
	Graph dag = parseDAG();

	dag.findSources();
	dag.DFS_VisitSources();
	dag.getMaxSequence();

	printf("%d %d\n", dag.numSources, dag.maxSequence);

	dag.clean();
	return 0;
}
